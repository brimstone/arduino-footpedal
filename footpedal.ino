#include "DigiKeyboard.h"

void setup() {

  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  DigiKeyboard.update();
  // don't need to set anything up to use DigiKeyboard
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
}


void loop() {
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  //digitalWrite(1, 0);
  //DigiKeyboard.delay(1000);
  //digitalWrite(1, 1);
  bool keydown = false;
  bool pedal = false;
  while (true) {
    pedal = digitalRead(0);
    if (!keydown && pedal) {
      keydown = true;
      /*
      DigiKeyboard.println("if err != nil {");
      DigiKeyboard.println("");
      DigiKeyboard.println("}");
      // http://www.usb.org/developers/hidpage/Hut1_12v2.pdf
      DigiKeyboard.sendKeyStroke(0x52);
      DigiKeyboard.sendKeyStroke(0x52);
      */
      DigiKeyboard.sendKeyStroke(KEY_F11, MOD_GUI_LEFT);
      digitalWrite(1, 1);
      DigiKeyboard.delay(500);
    } else if (keydown && !pedal) {
      keydown = false;
      digitalWrite(1, 0);
      DigiKeyboard.delay(500);
    }
  }
  DigiKeyboard.delay(100);
}

