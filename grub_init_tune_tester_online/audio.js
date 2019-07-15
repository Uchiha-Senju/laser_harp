var context = null, oscillator = null;

function startAudio() {
  context = new AudioContext();
  oscillator = context.createOscillator();
  oscillator.connect(context.destination);
  
  oscillator.frequency.value = 0;
};

// First entry is tempo, all others are tone-duartion pairs
//   Tempo - No. of notes per minute
//           Hence, 60 - one note per second, 300 - 5 notes per second, etc
//   Tone - Frequency of sound in hertz
//   Duration - Length of note defined by time unit set by the tempo
var grub_init_tune = "7680 784 32 1047 16 0 16 1047 32 1175 32 1319 32 1568 32 0 32 1568 32 1760 32 1760 32 2093 32 1760 32 1568 128 1760 32 1760 32 2093 32 1760 32 1568 16 0 16 1568 16 0 16 1319 64 1175 32 1047 32 1175 32 1319 32 1175 128";
var tone_list = grub_init_tune.split(' ');
for (var k in tone_list) {
  k = parseInt(k);
};

function setTune(init_tune) {
  grub_init_tune = init_tune;
  tone_list = grub_init_tune.split(' ');
  for (var k in tone_list) {
    k = parseInt(k);
  };
};

async function playTune(tone_list) {
  
  startAudio();
  
  // Start with sine wave
  oscillator.start(0);
  
  for (var i = 1; i < tone_list.length; i+=2) {
    // Set frequency
    oscillator.frequency.value = tone_list[i];
    // Wait for some time
    await new Promise(resolve => setTimeout(resolve, (1000 * 60 * tone_list[i+1] / tone_list[0])) );
    oscillator.frequency.value = 0;
  };
  
  
  // Stop
  oscillator.stop();
};

// playTune(tone_list);