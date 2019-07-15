// Source of tunes: Weeb-themes (search for it)
/*
##################################################################
# Grub Init Tunes {{{
##################################################################
# Arpeggio - Major
#GRUB_INIT_TUNE="2000 400 4 0 1 500 4 0 1 600 4 0 1 800 6"
# Close Encounters
#GRUB_INIT_TUNE="220 900 2 1000 2 800 2 400 2 600 3"
# Feel Good Inc
#GRUB_INIT_TUNE="300 369 2 329 2 82 1 0 2 82 1 92 1 98 1 0 1 130 1 0 1 123 7"
# Fur Elise
#GRUB_INIT_TUNE="480 420 1 400 1 420 1 400 1 420 1 315 1 370 1 335 1 282 3 180 1 215 1 282 1 315 3 213 1 262 1 315 1 335 3 213 1 420 1 400 1 420 1 400 1 420 1 315 1 370 1 335 1 282 3 180 1 215 1 282 1 315 3 213 1 330 1 315 1 282 3"
# KonoSuba2 ED
#GRUB_INIT_TUNE="7680 784 32 1047 16 0 16 1047 32 1175 32 1319 32 1568 32 0 32 1568 32 1760 32 1760 32 2093 32 1760 32 1568 128 1760 32 1760 32 2093 32 1760 32 1568 16 0 16 1568 16 0 16 1319 64 1175 32 1047 32 1175 32 1319 32 1175 128"
# Mario Mushroom
#GRUB_INIT_TUNE="1750 523 1 392 1 523 1 659 1 784 1 1047 1 784 1 415 1 523 1 622 1 831 1 622 1 831 1 1046 1 1244 1 1661 1 1244 1 466 1 587 1 698 1 932 1 1195 1 1397 1 1865 1 1397 1"
# Mario Theme
#GRUB_INIT_TUNE="1000 334 1 334 1 0 1 334 1 0 1 261 1 334 1 0 1 392 2 0 4 196 2"
# Mighty Morphin Power Rangers Communicator
#GRUB_INIT_TUNE="12288 659 64 659 64 587 32 659 64 784 64 659 64"
# On Wisconsin!
#GRUB_INIT_TUNE="600 294 5 277 2 330 4 294 5"
# PokeCenter
#GRUB_INIT_TUNE="288 880 1 0 1 880 1 0 1 880 1 698 1 1046 1"
# Rick and Morty - Intro 1
#GRUB_INIT_TUNE="300 466 3 554 1 523 1 622 1 415 1 369 1 349 4"
# Rick and Morty - Intro 2
#GRUB_INIT_TUNE="300 466 3 554 1 523 1 622 1 415 1 369 1 349 4"
# Shave and a Haircut
#GRUB_INIT_TUNE="400 523 2 392 1 392 1 440 2 392 2 1 2 494 2 523 2"
# Star Wars - Imperial March
#GRUB_INIT_TUNE="480 440 4 440 4 440 4 349 3 523 1 440 4 349 3 523 1 440 8 659 4 659 4 659 4 698 3 523 1 415 4 349 3 523 1 440 8"
# Twinkle, Twinkle
#GRUB_INIT_TUNE="300 294 1 294 1 440 1 440 1 494 1 494 1 440 2"
# U Can't Touch This
#GRUB_INIT_TUNE="300 147 2 130 1 123 1 110 1 440 1 440 1 82 1 98 1 392 1 392 1 123 1 110 1 440 1"
#################################################################}}}
*/

// Py code to generate c-code for arduino
/*

melodies = ["arpeggio", "close_encounters", "feel_good_inc", "fur_elise", "konosuba2_ed", "mario_mushroom", "mario_theme", "power_rangers", "on_wisconsin", "pokecenter", "rick_and_morty_1", "rick_and_morty_2", "shave_and_haircut", "imperial_march", "twinkle_twinkle", "cant_touch_this", "error"]
tones = ["2000 400 4 0 1 500 4 0 1 600 4 0 1 800 6",
         "220 900 2 1000 2 800 2 400 2 600 3",
         "300 369 2 329 2 82 1 0 2 82 1 92 1 98 1 0 1 130 1 0 1 123 7",
         "480 420 1 400 1 420 1 400 1 420 1 315 1 370 1 335 1 282 3 180 1 215 1 282 1 315 3 213 1 262 1 315 1 335 3 213 1 420 1 400 1 420 1 400 1 420 1 315 1 370 1 335 1 282 3 180 1 215 1 282 1 315 3 213 1 330 1 315 1 282 3",
         "7680 784 32 1047 16 0 16 1047 32 1175 32 1319 32 1568 32 0 32 1568 32 1760 32 1760 32 2093 32 1760 32 1568 128 1760 32 1760 32 2093 32 1760 32 1568 16 0 16 1568 16 0 16 1319 64 1175 32 1047 32 1175 32 1319 32 1175 128",
         "1750 523 1 392 1 523 1 659 1 784 1 1047 1 784 1 415 1 523 1 622 1 831 1 622 1 831 1 1046 1 1244 1 1661 1 1244 1 466 1 587 1 698 1 932 1 1195 1 1397 1 1865 1 1397 1",
         "1000 334 1 334 1 0 1 334 1 0 1 261 1 334 1 0 1 392 2 0 4 196 2",
         "12288 659 64 659 64 587 32 659 64 784 64 659 64",
         "600 294 5 277 2 330 4 294 5",
         "288 880 1 0 1 880 1 0 1 880 1 698 1 1046 1",
         "300 466 3 554 1 523 1 622 1 415 1 369 1 349 4",
         "300 466 3 554 1 523 1 622 1 415 1 369 1 349 4",
         "400 523 2 392 1 392 1 440 2 392 2 1 2 494 2 523 2",
         "480 440 4 440 4 440 4 349 3 523 1 440 4 349 3 523 1 440 8 659 4 659 4 659 4 698 3 523 1 415 4 349 3 523 1 440 8",
         "300 294 1 294 1 440 1 440 1 494 1 494 1 440 2",
         "300 147 2 130 1 123 1 110 1 440 1 440 1 82 1 98 1 392 1 392 1 123 1 110 1 440 1",
         "480 450 2 250 2"]

'''

print("const int no_of_melodies = " + len(melodies))
print()

'''
'''

for i in range(len(melodies)) :
    tone_list = str(int(((len(tones[i].split(' ')) - 1)/2)))
    for j in range(len(tones[i].split(' '))) :
        tone_list += ", " + str(tones[i].split(' ')[j])
    print("const int " + melodies[i] + "[" + str(len(tones[i].split(' ')) + 1) + "] = {" + tone_list + "};")
    
'''

for i in range(len(melodies)) :
    print("    case " + str(i) + " : ");
    print("      for (int i = 0; i < " + melodies[i] + "[0]; ++i) {")
    print("        if(log_debug_data) {")
    print("          Serial.print(\"\tPlaying tone - \");")
    print("          Serial.print(" + melodies[i] + "[(2*i + 2)]);")
    print("          Serial.print(\" : " + melodies[i] + "; delay - \");")
    print("          Serial.print(" + melodies[i] + "[(2*i + 3)] * 60 * 1000 / " + melodies[i] + "[1]);")
    print("          Serial.print('\\n');")
    print("        }")
    print("        tone(speaker_pin, " + melodies[i] + "[(2*i + 2)], " + melodies[i] + "[(2*i + 3)] * 60 * 1000 * slow_factor / " + melodies[i] + "[1]);")
    #print("        delay(" + melodies[i] + "[(2*i + 3)] * 60 * 1000 / " + melodies[i] + "[1]);")
    print("      }");
    print("      noTone(speaker_pin);");
    print("      break;");


 */

const int no_of_melodies = 16;

// First num is no. of tones, second is tempo (time unit = 60 seconds / tempo), rest are pitch duration pairs (duartion is in custom defined time units)
const int arpeggio[16] = {7, 2000, 400, 4, 0, 1, 500, 4, 0, 1, 600, 4, 0, 1, 800, 6};
const int close_encounters[12] = {5, 220, 900, 2, 1000, 2, 800, 2, 400, 2, 600, 3};
const int feel_good_inc[24] = {11, 300, 369, 2, 329, 2, 82, 1, 0, 2, 82, 1, 92, 1, 98, 1, 0, 1, 130, 1, 0, 1, 123, 7};
const int fur_elise[72] = {35, 480, 420, 1, 400, 1, 420, 1, 400, 1, 420, 1, 315, 1, 370, 1, 335, 1, 282, 3, 180, 1, 215, 1, 282, 1, 315, 3, 213, 1, 262, 1, 315, 1, 335, 3, 213, 1, 420, 1, 400, 1, 420, 1, 400, 1, 420, 1, 315, 1, 370, 1, 335, 1, 282, 3, 180, 1, 215, 1, 282, 1, 315, 3, 213, 1, 330, 1, 315, 1, 282, 3};
const int konosuba2_ed[58] = {28, 7680, 784, 32, 1047, 16, 0, 16, 1047, 32, 1175, 32, 1319, 32, 1568, 32, 0, 32, 1568, 32, 1760, 32, 1760, 32, 2093, 32, 1760, 32, 1568, 128, 1760, 32, 1760, 32, 2093, 32, 1760, 32, 1568, 16, 0, 16, 1568, 16, 0, 16, 1319, 64, 1175, 32, 1047, 32, 1175, 32, 1319, 32, 1175, 128};
const int mario_mushroom[52] = {25, 1750, 523, 1, 392, 1, 523, 1, 659, 1, 784, 1, 1047, 1, 784, 1, 415, 1, 523, 1, 622, 1, 831, 1, 622, 1, 831, 1, 1046, 1, 1244, 1, 1661, 1, 1244, 1, 466, 1, 587, 1, 698, 1, 932, 1, 1195, 1, 1397, 1, 1865, 1, 1397, 1};
const int mario_theme[24] = {11, 1000, 334, 1, 334, 1, 0, 1, 334, 1, 0, 1, 261, 1, 334, 1, 0, 1, 392, 2, 0, 4, 196, 2};
const int power_rangers[14] = {6, 12288, 659, 64, 659, 64, 587, 32, 659, 64, 784, 64, 659, 64};
const int on_wisconsin[10] = {4, 600, 294, 5, 277, 2, 330, 4, 294, 5};
const int pokecenter[16] = {7, 288, 880, 1, 0, 1, 880, 1, 0, 1, 880, 1, 698, 1, 1046, 1};
const int rick_and_morty_1[16] = {7, 300, 466, 3, 554, 1, 523, 1, 622, 1, 415, 1, 369, 1, 349, 4};
const int rick_and_morty_2[16] = {7, 300, 466, 3, 554, 1, 523, 1, 622, 1, 415, 1, 369, 1, 349, 4};
const int shave_and_haircut[18] = {8, 400, 523, 2, 392, 1, 392, 1, 440, 2, 392, 2, 1, 2, 494, 2, 523, 2};
const int imperial_march[38] = {18, 480, 440, 4, 440, 4, 440, 4, 349, 3, 523, 1, 440, 4, 349, 3, 523, 1, 440, 8, 659, 4, 659, 4, 659, 4, 698, 3, 523, 1, 415, 4, 349, 3, 523, 1, 440, 8};
const int twinkle_twinkle[16] = {7, 300, 294, 1, 294, 1, 440, 1, 440, 1, 494, 1, 494, 1, 440, 2};
const int cant_touch_this[28] = {13, 300, 147, 2, 130, 1, 123, 1, 110, 1, 440, 1, 440, 1, 82, 1, 98, 1, 392, 1, 392, 1, 123, 1, 110, 1, 440, 1};
const int error[6] = {2, 480, 450, 2, 250, 2};

void play_melody(int melody_id, int speaker_pin, float slow_factor = 1, bool log_debug_data = false) {
  if (log_debug_data) {
    Serial.print("Playing tune - ");
    Serial.print(melody_id);
    Serial.print('\n');
  }
  switch (melody_id) {
    case 0 : 
      for (int i = 0; i < arpeggio[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(arpeggio[(2*i + 2)]);
          Serial.print(" : arpeggio; delay - ");
          Serial.print(arpeggio[(2*i + 3)] * 60 * 1000 / arpeggio[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, arpeggio[(2*i + 2)], arpeggio[(2*i + 3)] * 60 * 1000 * slow_factor / arpeggio[1]);
      }
      noTone(speaker_pin);
      break;
    case 1 : 
      for (int i = 0; i < close_encounters[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(close_encounters[(2*i + 2)]);
          Serial.print(" : close_encounters; delay - ");
          Serial.print(close_encounters[(2*i + 3)] * 60 * 1000 / close_encounters[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, close_encounters[(2*i + 2)], close_encounters[(2*i + 3)] * 60 * 1000 * slow_factor / close_encounters[1]);
      }
      noTone(speaker_pin);
      break;
    case 2 : 
      for (int i = 0; i < feel_good_inc[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(feel_good_inc[(2*i + 2)]);
          Serial.print(" : feel_good_inc; delay - ");
          Serial.print(feel_good_inc[(2*i + 3)] * 60 * 1000 / feel_good_inc[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, feel_good_inc[(2*i + 2)], feel_good_inc[(2*i + 3)] * 60 * 1000 * slow_factor / feel_good_inc[1]);
      }
      noTone(speaker_pin);
      break;
    case 3 : 
      for (int i = 0; i < fur_elise[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(fur_elise[(2*i + 2)]);
          Serial.print(" : fur_elise; delay - ");
          Serial.print(fur_elise[(2*i + 3)] * 60 * 1000 / fur_elise[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, fur_elise[(2*i + 2)], fur_elise[(2*i + 3)] * 60 * 1000 * slow_factor / fur_elise[1]);
      }
      noTone(speaker_pin);
      break;
    case 4 : 
      for (int i = 0; i < konosuba2_ed[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(konosuba2_ed[(2*i + 2)]);
          Serial.print(" : konosuba2_ed; delay - ");
          Serial.print(konosuba2_ed[(2*i + 3)] * 60 * 1000 / konosuba2_ed[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, konosuba2_ed[(2*i + 2)], konosuba2_ed[(2*i + 3)] * 60 * 1000 * slow_factor / konosuba2_ed[1]);
      }
      noTone(speaker_pin);
      break;
    case 5 : 
      for (int i = 0; i < mario_mushroom[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(mario_mushroom[(2*i + 2)]);
          Serial.print(" : mario_mushroom; delay - ");
          Serial.print(mario_mushroom[(2*i + 3)] * 60 * 1000 / mario_mushroom[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, mario_mushroom[(2*i + 2)], mario_mushroom[(2*i + 3)] * 60 * 1000 * slow_factor / mario_mushroom[1]);
      }
      noTone(speaker_pin);
      break;
    case 6 : 
      for (int i = 0; i < mario_theme[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(mario_theme[(2*i + 2)]);
          Serial.print(" : mario_theme; delay - ");
          Serial.print(mario_theme[(2*i + 3)] * 60 * 1000 / mario_theme[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, mario_theme[(2*i + 2)], mario_theme[(2*i + 3)] * 60 * 1000 * slow_factor / mario_theme[1]);
      }
      noTone(speaker_pin);
      break;
    case 7 : 
      for (int i = 0; i < power_rangers[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(power_rangers[(2*i + 2)]);
          Serial.print(" : power_rangers; delay - ");
          Serial.print(power_rangers[(2*i + 3)] * 60 * 1000 / power_rangers[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, power_rangers[(2*i + 2)], power_rangers[(2*i + 3)] * 60 * 1000 * slow_factor / power_rangers[1]);
      }
      noTone(speaker_pin);
      break;
    case 8 : 
      for (int i = 0; i < on_wisconsin[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(on_wisconsin[(2*i + 2)]);
          Serial.print(" : on_wisconsin; delay - ");
          Serial.print(on_wisconsin[(2*i + 3)] * 60 * 1000 / on_wisconsin[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, on_wisconsin[(2*i + 2)], on_wisconsin[(2*i + 3)] * 60 * 1000 * slow_factor / on_wisconsin[1]);
      }
      noTone(speaker_pin);
      break;
    case 9 : 
      for (int i = 0; i < pokecenter[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(pokecenter[(2*i + 2)]);
          Serial.print(" : pokecenter; delay - ");
          Serial.print(pokecenter[(2*i + 3)] * 60 * 1000 / pokecenter[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, pokecenter[(2*i + 2)], pokecenter[(2*i + 3)] * 60 * 1000 * slow_factor / pokecenter[1]);
      }
      noTone(speaker_pin);
      break;
    case 10 : 
      for (int i = 0; i < rick_and_morty_1[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(rick_and_morty_1[(2*i + 2)]);
          Serial.print(" : rick_and_morty_1; delay - ");
          Serial.print(rick_and_morty_1[(2*i + 3)] * 60 * 1000 / rick_and_morty_1[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, rick_and_morty_1[(2*i + 2)], rick_and_morty_1[(2*i + 3)] * 60 * 1000 * slow_factor / rick_and_morty_1[1]);
      }
      noTone(speaker_pin);
      break;
    case 11 : 
      for (int i = 0; i < rick_and_morty_2[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(rick_and_morty_2[(2*i + 2)]);
          Serial.print(" : rick_and_morty_2; delay - ");
          Serial.print(rick_and_morty_2[(2*i + 3)] * 60 * 1000 / rick_and_morty_2[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, rick_and_morty_2[(2*i + 2)], rick_and_morty_2[(2*i + 3)] * 60 * 1000 * slow_factor / rick_and_morty_2[1]);
      }
      noTone(speaker_pin);
      break;
    case 12 : 
      for (int i = 0; i < shave_and_haircut[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(shave_and_haircut[(2*i + 2)]);
          Serial.print(" : shave_and_haircut; delay - ");
          Serial.print(shave_and_haircut[(2*i + 3)] * 60 * 1000 / shave_and_haircut[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, shave_and_haircut[(2*i + 2)], shave_and_haircut[(2*i + 3)] * 60 * 1000 * slow_factor / shave_and_haircut[1]);
      }
      noTone(speaker_pin);
      break;
    case 13 : 
      for (int i = 0; i < imperial_march[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(imperial_march[(2*i + 2)]);
          Serial.print(" : imperial_march; delay - ");
          Serial.print(imperial_march[(2*i + 3)] * 60 * 1000 / imperial_march[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, imperial_march[(2*i + 2)], imperial_march[(2*i + 3)] * 60 * 1000 * slow_factor / imperial_march[1]);
      }
      noTone(speaker_pin);
      break;
    case 14 : 
      for (int i = 0; i < twinkle_twinkle[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(twinkle_twinkle[(2*i + 2)]);
          Serial.print(" : twinkle_twinkle; delay - ");
          Serial.print(twinkle_twinkle[(2*i + 3)] * 60 * 1000 / twinkle_twinkle[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, twinkle_twinkle[(2*i + 2)], twinkle_twinkle[(2*i + 3)] * 60 * 1000 * slow_factor / twinkle_twinkle[1]);
      }
      noTone(speaker_pin);
      break;
    case 15 : 
      for (int i = 0; i < cant_touch_this[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(cant_touch_this[(2*i + 2)]);
          Serial.print(" : cant_touch_this; delay - ");
          Serial.print(cant_touch_this[(2*i + 3)] * 60 * 1000 / cant_touch_this[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, cant_touch_this[(2*i + 2)], cant_touch_this[(2*i + 3)] * 60 * 1000 * slow_factor / cant_touch_this[1]);
      }
      noTone(speaker_pin);
      break;
    case 16 : 
      for (int i = 0; i < error[0]; ++i) {
        if(log_debug_data) {
          Serial.print("  Playing tone - ");
          Serial.print(error[(2*i + 2)]);
          Serial.print(" : error; delay - ");
          Serial.print(error[(2*i + 3)] * 60 * 1000 / error[1]);
          Serial.print('\n');
        }
        tone(speaker_pin, error[(2*i + 2)], error[(2*i + 3)] * 60 * 1000 * slow_factor / error[1]);
      }
      noTone(speaker_pin);
      break;
  }
}
