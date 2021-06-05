#include <Arduino.h>
#include <BLEDevice.h>

#include "BLELight.h"

BLELight bleLight;

void setup() {
  Serial.begin(115200);
  BLEDevice::init("");
  
  if(bleLight.connect(BLEAddress("ff:ff:d0:07:57:f4"))) { // Note: Sometimes need to connect multiple times 
    bleLight.turnOff();
    delay(1000);
    bleLight.turnOn();
    delay(1000);
    
    for (uint8_t i=0; i<100; i++) {
      bleLight.setColor(0xFF, 0xFF, 0xFF, i, true); // White
      delay(100);
    }

    bleLight.setColor(0xFF, 0x00, 0x00, 100, false);
    delay(1000); 

    bleLight.setColor(0x00, 0xFF, 0x00, 100, false);
    delay(1000);

    bleLight.setColor(0x00, 0x00, 0xFF, 100, false);
    delay(1000);

    bleLight.setColor(250, 134, 17, 100, true); //Set to Warm-White
    delay(5000);    

    bleLight.setMode(RGB_STROBE, 30);
  }
}


void loop() {
  
}
