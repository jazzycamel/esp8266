/*
When run, this sketch will test and report the size of the flash memory used by the ESP8266.
*/
#include <Arduino.h>

extern "C" {
  #include "user_interface.h"
}

#define MBIT ((1024*1024)/8)

bool testFlash2(uint32_t pAddr){
  uint32_t temp;
  return spi_flash_read(pAddr, &temp, 1)==SPI_FLASH_RESULT_OK;
}

bool testFlash(uint32_t pAddr){
  Serial.print("[Flash] Address: 0x");
  Serial.print(pAddr, HEX);
  Serial.print(" - ");
  Serial.print(pAddr, DEC);
  Serial.print(" ");

  if(testFlash2(pAddr)){
    Serial.println("OK");
    return true;
  }
  Serial.println("FAIL");
  return false;
}

void setup() {
  Serial.begin(115200);
  while(!Serial) continue;
  delay(200);

  Serial.println();

  for(uint8_t t=4; t>0; t--){
    Serial.print("[SETUP] BOOT WAIT ");
    Serial.print(t);
    Serial.println("...");
    Serial.flush();
    delay(1000);
  }

  Serial.print("[SETUP] Flash ID: 0x");
  Serial.println(spi_flash_get_id(), HEX);

  uint32_t step=MBIT, addr=MBIT;
  while(1){
    if(testFlash(addr)) addr+=step;
    else {
      step/=2;
      addr-=step;
    }

    if(step<=1){
      testFlash(addr);
      break;
    }
  }

  Serial.println("----------------------");
  Serial.print("[FLASH] Size: 0x");
  Serial.print(addr, HEX);
  Serial.print(" - ");
  Serial.println(addr, DEC);
  Serial.println("Finished.");
}

void loop() {}
