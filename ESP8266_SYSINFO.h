/*************************************************
 *
 * ESP8266 SYSINFO LIBRARY
 * (UTILITY FUNCTIONS TO PRINT SYSTEM PARAMETERS)
 *
 * JULY 11  2017
 *
 * REFERENCES
 * -------------
 *	(1) CRC8
 *			http://www.robotomy.eu/crc8/
 *
 * ANKIT BHATNAGAR
 * ANKIT.BHATNAGARINDIA@GMAIL.COM
 *************************************************/

#ifndef _ESP8266_SYSINFO_H_
#define _ESP8266_SYSINFO_H_

#include "osapi.h"
#include "ets_sys.h"
#include "os_type.h"
#include "user_interface.h"

//CUSTOM VARIABLE STRUCTURES/////////////////////////////

//FUNCTION PROTOTYPES/////////////////////////////////////
//CONFIGURATION FUNCTIONS

//CONTROL FUNCTIONS
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintFlashChipId(void);
uint32_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetFlashChipId(void);
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemFlashMap(void);
uint16_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSystemFlashMap(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintCpuFrequency(void);
uint32_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetCpuFrequency(void);
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemMac(void);
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSystemMac(uint8_t* mac);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintResetDetails(void);

uint8_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetCRC8(char* data, uint16_t len);
//END FUNCTION PROTOTYPES/////////////////////////////////

#endif
