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

#include "ESP8266_SYSINFO.h"

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintFlashChipId(void)
{
    //PRINT SYSTEM FLASH CHIP ID
    
     uint32_t chip_id = spi_flash_get_id();
     os_printf("ESP8266 : SYSINFO : Flash chip id = 0x%x\n", chip_id);
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemFlashMap(void)
{
    //PRINT SYSTEM FLASH MAP

    enum flash_size_map map = system_get_flash_size_map();
    os_printf("ESP8266 : SYSINFO : System flash map = %u\n", map);
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemMac(void)
{
    //PRINT SYSTEM MAC ADDRESS

    char sys_mac[6];
    wifi_get_macaddr(STATION_IF, sys_mac);
    os_printf("ESP8266 : SYSINFO : System MAC : %02X:%02X:%02X:%02X:%02X:%02X:\n", sys_mac[0], sys_mac[1], sys_mac[2], sys_mac[3], sys_mac[4], sys_mac[5]);
}


