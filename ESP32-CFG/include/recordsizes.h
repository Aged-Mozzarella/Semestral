#ifndef RECORDSIZES_H
#define RECORDSIZES_H

// Maximum size for an URL
#define EEPROM_SIZE_URL 128
// Maximum size for a WiFi password
#define EEPROM_SIZE_PASS 64
// Maximum size for a WiFi SSID
#define EEPROM_SIZE_SSID 32
// Maximum size for an IP address
#define EEPROM_SIZE_IP 24
// Maximum size for a uint16_t
#define EEPROM_SIZE_WRITE_COUNT 2
// Total size of the EEPROM
#define EEPROM_SIZE_TOTAL 512

// Memory locations of records

#define EEPROM_LOC_URL_WEATHER 0
#define EEPROM_LOC_URL_BUS_A 128
#define EEPROM_LOC_URL_BUS_B 256
#define EEPROM_LOC_WIFI_PASS 384
#define EEPROM_LOC_WIFI_SSID 448
#define EEPROM_LOC_IP 480
#define EEPROM_LOC_WRITE_COUNT 504

#endif // RECORDSIZES_H
