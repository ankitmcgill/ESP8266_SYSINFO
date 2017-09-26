/*************************************************
 *
 * ESP8266 SYSINFO LIBRARY
 * (UTILITY FUNCTIONS TO PRINT SYSTEM PARAMETERS)
 *
 * JULY 11  2017
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
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemFlashMap(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintCpuFrequency(void);
void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemMac(void);

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintResetDetails(void);
//END FUNCTION PROTOTYPES/////////////////////////////////

#endif
