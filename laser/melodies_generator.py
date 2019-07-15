
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
