/*************************************************
 *
 * ESP8266 SYSINFO LIBRARY
 * (UTILITY FUNCTIONS TO PRINT SYSTEM PARAMETERS)
 *
 * JULY 11	2017
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

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintCpuFrequency(void)
{
		//PRINT CPU FREQUENCY IN MHZ

		uint32_t freq = system_get_cpu_freq();
		os_printf("ESP8266 : SYSINFO : CPU Frequency = %u\n", freq);
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemMac(void)
{
		//PRINT SYSTEM MAC ADDRESS

		char sys_mac[6];
		wifi_get_macaddr(STATION_IF, sys_mac);
		os_printf("ESP8266 : SYSINFO : System MAC : %02X:%02X:%02X:%02X:%02X:%02X:\n", sys_mac[0], sys_mac[1], sys_mac[2], sys_mac[3], sys_mac[4], sys_mac[5]);
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintResetDetails(void)
{
		//PRINT SYSTEM RESET DETIALS

		struct reset_info* r_reason = NULL;

		if((r_reason = system_get_rst_info()) != NULL)
		{
				switch(r_reason->reason)
				{
						case REASON_DEFAULT_RST:
								os_printf("ESP8266 : SYSINFO : default reset\n");
								break;

						case REASON_DEFAULT_RST:
								os_printf("ESP8266 : SYSINFO : default reset\n");
								break;

						case REASON_WDT_RST:
								os_printf("ESP8266 : SYSINFO : hard wdt reset\n");
								break;

						case REASON_EXCEPTION_RST:
								os_printf("ESP8266 : SYSINFO : exception reset\n");
								break;

						case REASON_SOFT_WDT_RST:
								os_printf("ESP8266 : SYSINFO : soft wdt reset\n");
								break;

						case REASON_SOFT_RESTART:
								os_printf("ESP8266 : SYSINFO : soft restart\n");
								break;

						case REASON_DEEP_SLEEP_AWAKE:
								os_printf("ESP8266 : SYSINFO : deep sleep awake\n");
								break;

						case REASON_EXT_SYS_RST:
								os_printf("ESP8266 : SYSINFO : external sys reset\n");
								break;
				}
				os_printf("ESP8266 : SYSINFO : exccause = 0x%x epc1 = 0x%x epc2 = 0x%x epc3 = 0x%x\n", r_reason->exccause, r_reason->epc1, r_reason->epc2, r_reason->epc3);
		}
		else
		{
				os_printf("ESP8266 : SYSINFO : Cannot determine reset reason !\n");
		}
}
