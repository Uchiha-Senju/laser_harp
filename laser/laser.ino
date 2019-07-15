#include "melodies.h"

// Time constants
const int time_pulse = 50;
const int max_play_time = 50;
const int input_trigger_time = 40;
const int mode_switch_trigger_time = 20;
const int input_entry_time = 10;
const int input_confirm_tone_duration = 1;
const int count_frequency_time = 5;

// Pin constants
const int in_pins[6] = {A0, A1, A2, A3, A4, A5};
const int out_pins[6] = {2, 3, 4, 5, 6, 7};
const int pin_notes[6] = {2489, 2637, 2793, 2959, 3322, 3520};
const int buzzer_pin = 8;

const float adjustment_ratio = 0.5;
const int no_of_pins = 4;

// Laser stuff
int in_pin_thresholds[6] = {0, 0, 0, 0, 0, 0};
bool input_mode = false;
int melody_id_input = 0;
int in_pin_hist[6] = {0, 0, 0, 0, 0, 0};

// Function declarations
void calibrateHarp(const int, const float, const int*, const int*, int*);
void getInput(const int, int, const int, const int, const int, const int, const int*, int*, const int*, int*, const int*);
void playHarp(const int, const int, const int, const int, const int*, int*, const int*, const int*);
void sendDebugInfo(void);
bool checkForModeSwitch(const int, const int[], const int);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  for (int i = 0; i < no_of_pins; ++i) {
    pinMode(out_pins[i], OUTPUT);
    digitalWrite(out_pins[i], LOW);
    
    pinMode(in_pins[i], INPUT);
  }
  
  calibrateHarp(no_of_pins, adjustment_ratio, in_pins, out_pins, in_pin_thresholds);
  
  //Setup for debugging
  Serial.begin(9600);

  for(int i = 0; i < (1 << no_of_pins); ++i) {
    for (int j = 0; j < no_of_pins; ++j) {
      digitalWrite(out_pins[j], ((i >> j) % 2) );
    }
    delay(time_pulse * count_frequency_time);
  }
  
  for (int i = 0; i < no_of_pins; ++i) 
    digitalWrite(out_pins[i], HIGH);
}

void loop() {
  
  bool all_triggered = true;
  
  if (input_mode) {
    // If in input mode, recieve input
    digitalWrite(LED_BUILTIN, HIGH);
    getInput(no_of_pins, melody_id_input, time_pulse, max_play_time, input_trigger_time, input_confirm_tone_duration, buzzer_pin, in_pins, in_pin_hist, in_pin_thresholds, pin_notes);

  // Go into input or out of input if all strings are triggered
    if ( checkForModeSwitch(no_of_pins, in_pin_hist, mode_switch_trigger_time) ) {
      input_mode = false;
      Serial.println("switched out of input");
      delay(1000);
    }
  } else if (melody_id_input != 0) {
    // Once input is received, play the corresponding melody, and set it to send debug data
    digitalWrite(LED_BUILTIN, LOW);
    play_melody(melody_id_input, buzzer_pin, 10000000, true);
    melody_id_input = 0;
  } else {
    // Play the harp
    digitalWrite(LED_BUILTIN, LOW);
    playHarp(no_of_pins, time_pulse, max_play_time, buzzer_pin, in_pins, in_pin_hist, pin_notes, in_pin_thresholds);
  }

  // Go into input or out of input if all strings are triggered
  if ( checkForModeSwitch(no_of_pins, in_pin_hist, mode_switch_trigger_time) ) {
    input_mode = true;
    Serial.println("switched into input");
    delay(1000);
  }
  /*
  
  play_melody(melody_id_input, buzzer_pin);
  delay(2000);
  melody_id_input++;
  if (melody_id_input >= no_of_melodies)
    melody_id_input = 0;
  */
  sendDebugInfo();
  
}

//Send debugging info (variable data, state data, etc) to the serial monitor
void sendDebugInfo() {
  Serial.print("\nTheresholds : ");
  for (int i = 0; i < no_of_pins; ++i) {
    Serial.print(in_pin_thresholds[i]);
    Serial.print("  ");
  }
  
  Serial.print("\n Input hist : ");
  for (int i = 0; i < no_of_pins; ++i) {
    Serial.print(in_pin_hist[i]);
    Serial.print("  ");
  }
  
  Serial.print("\n Input mode : ");
  Serial.print(input_mode);
  
  Serial.print("\nMelody input : ");
  Serial.print(melody_id_input);
  
  Serial.print("\n\n\n");
}

bool checkForModeSwitch(const int no_of_pins, int input_history[], const int trigger_time) {
  bool all_triggered = true;
  for (int i = 0; i < no_of_pins; ++i) 
    all_triggered &= input_history[i] >= trigger_time;
  if (all_triggered) {
    for (int i = 0; i < no_of_pins; ++i) 
      input_history[i] = 0;
    return true;
  }
  return false;
}

// Read input and play the corresponding frequencies
void playHarp(const int pins_no, const int time_step, const int max_time, const int speaker_pin, const int inputs[], int input_history[], const int notes[], const int thresholds[]) {
  for (int i = 0; i < pins_no; ++i) {
    if (analogRead(inputs[i]) > thresholds[i] and input_history[i] < max_time) {
      tone(speaker_pin, notes[i]);
      delay(time_step);
      noTone(speaker_pin);
      input_history[i]++;
    } else if (analogRead(inputs[i]) > thresholds[i] and input_history[i] >= max_time) {
      ; // Do nothing
    } else if (analogRead(inputs[i]) < thresholds[i]) {
      input_history[i] = 0;
    }
  }
}

// Get input from the lasers
void getInput(const int pins_no, int input, const int time_step, const int max_time, const int trigger_time, const int confirm_play_time, const int speaker_pin, const int inputs[], int input_history[], int thresholds[],const int notes[]) {
  int triggered_pin = pins_no;
  int no_of_triggered_pins = 0;
  // update history of all input pins
  for (int i = 0; i < pins_no; ++i) {
    if (analogRead(inputs[i]) > thresholds[i] and input_history[i] < max_time) {
      input_history[i]++;
    } else if (analogRead(inputs[i]) > thresholds[i] and input_history[i] >= max_time) {
      ; // Do nothing
    } else if (analogRead(inputs[i]) < thresholds[i]) {
      input_history[i] = 0;
    }
  }
  // See if only one pin is triggered and which one
  for (int i = 0; i < pins_no; ++i) {
    if (input_history[i] >= trigger_time) {
      no_of_triggered_pins++;
      triggered_pin = i;
    }
  }
  // count up input in base(no_of_pins) if only one pin is triggered
  if (no_of_triggered_pins == 1) { 
    melody_id_input *= pins_no;
    melody_id_input += triggered_pin;
    
    in_pin_hist[triggered_pin] = 0;
    
    tone(speaker_pin, notes[triggered_pin]);
    delay(time_pulse * confirm_play_time);
    noTone(speaker_pin);
    
  }
}

// Calibrate percieved brightness for a new environment
void calibrateHarp(const int pins_no, const float lerp_ratio, const int inputs[], const int outputs[], int thresholds[]) {
  int brightness;
  
  for (int i = 0; i < pins_no; ++i) {
    // Get brightness values with no lasers on
    brightness = analogRead(inputs[i]);
    thresholds[i] = brightness;
    delay(50);
  }
  for (int i = 0; i < pins_no; ++i) 
    digitalWrite(outputs[i], HIGH);

  
  for (int i = 0; i < pins_no; ++i) {
    // Get brightness values with lasers on
    brightness = analogRead(inputs[i]);
    // lineraly interpolate between no-laser-brightness and laser-brightness, according to the adjustment ratio
    thresholds[i] = (1 - lerp_ratio) * brightness + lerp_ratio * thresholds[i];
    delay(50);
  }
  for (int i = 0; i < pins_no; ++i) 
    digitalWrite(outputs[i], LOW);
}
