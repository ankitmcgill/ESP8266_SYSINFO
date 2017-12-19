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
 *		http://www.robotomy.eu/crc8/
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
#include "spi_flash.h"


//CUSTOM VARIABLE STRUCTURES/////////////////////////////
typedef enum
{
    FLASH_MODE_QIO = 0,
    FLASH_MODE_QOUT = 1,
    FLASH_MODE_DIO = 2,
    FLASH_MODE_DOUT = 3,
    FLASH_MODE_UNKNOWN
}ESP8266_SYSINFO_FLASH_MODE;

//FUNCTION PROTOTYPES/////////////////////////////////////
//CONFIGURATION FUNCTIONS

//CONTROL FUNCTIONS
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintFlashChipId(void);
uint32_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetFlashChipId(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintFlashChipMode(void);
ESP8266_SYSINFO_FLASH_MODE ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetFlashChipMode(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemFlashMap(void);
uint16_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSystemFlashMap(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintCpuFrequency(void);
uint32_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetCpuFrequency(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemMac(void);
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSystemMac(uint8_t* mac);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintESP8266ChipId(void);
uint64_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetESP8266ChipId(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSDKVersion(void);
const char* ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSDKVersion(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintResetDetails(void);
struct rst_info* ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetResetDetails(void);

uint8_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetCRC8(char* data, uint16_t len);
//END FUNCTION PROTOTYPES/////////////////////////////////

#endif
