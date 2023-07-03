#define MILLIS_TIMEOUT 100
#define BYTES_TO_READ 8

#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

#include <stdint.h>

// Array of ints for enabling live feed of data from the unit
// livefeed - 6C 69 76 65 66 65 65 64
const uint8_t CMD_LIVE_FEED[] = {0x6C, 0x69, 0x76, 0x65, 0x66, 0x65, 0x65, 0x64};

// Array of ints for enabling configuration of the unit
// configur - 63 6F 6E 66 69 67 75 72
const uint8_t CMD_CONFIGURE[] = {0x63, 0x6F, 0x6E, 0x66, 0x69, 0x67, 0x75, 0x72};

// Array of ints for stopping all data feed from the unit
// stop_cmd - 73 74 6F 70 5F 63 6D 64
const uint8_t CMD_STOP[] = {0x73, 0x74, 0x6F, 0x70, 0x5F, 0x63, 0x6D, 0x64};
#endif // SERIALCOMMANDS_H

char buf[BYTES_TO_READ] = {};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  memset(&buf, 0, sizeof(buf));
}

void loop() {
  checkSerial();
  delay(50);
}

void checkSerial(){
  if(Serial.available() >= BYTES_TO_READ){
    Serial.readBytes(buf, BYTES_TO_READ);
    if(!memcmp(&buf, &CMD_LIVE_FEED, BYTES_TO_READ)){
      Serial.print("LIVE FEEDING");
    }else if(!memcmp(&buf, &CMD_CONFIGURE, BYTES_TO_READ)){
      Serial.print("CONFIGURING");
    }else if(!memcmp(&buf, &CMD_STOP, BYTES_TO_READ)){
      Serial.print("STOPPING EVERYTHING");
    }else{
      Serial.print("UNKNOWN COMMAND"); 
    }
    memset(&buf, 0, sizeof(buf));
   flushSerial();
  }
}

void flushSerial(){
  while(Serial.available() > 0){
    char t = Serial.read();
  }
}
