#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

#include <stdint.h>
// Standard control commands arrays length
const uint8_t BYTES_TO_READ = 8;

// Length of the entire configuration string
// 3 (header) + 504 (actual data) + 5 (splitters)
const uint16_t CONFIG_STRING_LEN = 512;

// Array of ints for enabling live feed of data from the unit
// livefeed - 6C 69 76 65 66 65 65 64
const uint8_t CMD_LIVE_FEED[] = {0x6C, 0x69, 0x76, 0x65, 0x66, 0x65, 0x65, 0x64};

// Array of ints for enabling configuration of the unit
// configur - 63 6F 6E 66 69 67 75 72
const uint8_t CMD_CONFIGURE[] = {0x63, 0x6F, 0x6E, 0x66, 0x69, 0x67, 0x75, 0x72};

// Array of ints for stopping all data feed from the unit
// stop_cmd - 73 74 6F 70 5F 63 6D 64
const uint8_t CMD_STOP[] = {0x73, 0x74, 0x6F, 0x70, 0x5F, 0x63, 0x6D, 0x64};

// Array of ints for confirming configuration data of the unit
// savedata - 73 61 76 65 64 61 74 61
const uint8_t CMD_SAVE[] = {0x73, 0x61, 0x76, 0x65, 0x64, 0x61, 0x71, 0x61};


// Command confirmation control characters
// Configuration begin acknowledged
const char * CONFIG_BEGIN = "*B*";
// Configuration data received
const char * CONFIG_RECEIVED = "*R*";
// Configuration saved
const char * CONFIG_SAVE = "*S*";
// Illegal save request
const char * CONFIG_ILLEGAL = "*I*";
// Bad header
const char * CONFIG_BAD_HEADER = "*H*";
// Bad contents
const char * CONFIG_BAD_CONTENT = "*X*";

// Incoming config string header
const char * CONFIG_HEADER = "*C*";

#endif // SERIALCOMMANDS_H
