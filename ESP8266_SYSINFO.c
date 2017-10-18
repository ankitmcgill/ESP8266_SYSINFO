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

#include "ESP8266_SYSINFO.h"

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintFlashChipId(void)
{
    //PRINT SYSTEM FLASH CHIP ID

    uint32_t chip_id = spi_flash_get_id();
    os_printf("ESP8266 : SYSINFO : Flash chip id = 0x%x\n", chip_id);
}

uint32_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetFlashChipId(void)
{
    //RETURN SYSTEM FLASH CHIP ID

    uint32_t chip_id = spi_flash_get_id();
    return chip_id;
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemFlashMap(void)
{
    //PRINT SYSTEM FLASH MAP

    enum flash_size_map map = system_get_flash_size_map();
    os_printf("ESP8266 : SYSINFO : System flash map = %u\n", map);
}

uint16_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSystemFlashMap(void)
{
    //RETURN SYSTEM FLASH MAP

    enum flash_size_map map = system_get_flash_size_map();
    return map;
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintFlashChipMode(void)
{
    //PRINT FLASH CHIP MODE
    //RESIDES IN HEADER (FIRST 4 BYTES) OF EAGLE.FLASH.BIN LOCATED
    //AT FLASH ADDRESS 0x00000

    uint32_t header;
    SpiFlashOpResult result = spi_flash_read(0x00000, &header, 4);

    if(result == SPI_FLASH_RESULT_OK)
    {
        result = result & 0x00F0;
        result = result >> 8;

        switch(result)
        {
            case 0:
                os_printf("ESP8266 : SYSINFO : Flash Chip Mode = FLASH_MODE_QIO\n"); 
                break;
            case 1:
                os_printf("ESP8266 : SYSINFO : Flash Chip Mode = FLASH_MODE_QOUT\n"); 
                break;
            case 2:
                os_printf("ESP8266 : SYSINFO : Flash Chip Mode = FLASH_MODE_DIO\n"); 
                break;
            case 3:
                os_printf("ESP8266 : SYSINFO : Flash Chip Mode = FLASH_MODE_DOUT\n"); 
                break;
            default:
                os_printf("ESP8266 : SYSINFO : Flash Chip Mode = FLASH_MODE_UNKNOWN\n"); 
                break;
        }
        return;
    }
    os_printf("ESP8266 : SYSINFO : Flash Chip Mode = FLASH_MODE_UNKNOWN\n"); 
}

ESP8266_SYSINFO_FLASH_MODE ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetFlashChipMode(void)
{
    //RETURN FLASH CHIP MODE
    //RESIDES IN HEADER (FIRST 4 BYTES) OF EAGLE.FLASH.BIN LOCATED
    //AT FLASH ADDRESS 0x00000

    uint32_t header;
    SpiFlashOpResult result = spi_flash_read(0x00000, &header, 4);

    if(result == SPI_FLASH_RESULT_OK)
    {
        result = result & 0x00F0;
        result = result >> 8;
        return (ESP8266_SYSINFO_FLASH_MODE)result;
    }
    return FLASH_MODE_UNKNOWN;
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintCpuFrequency(void)
{
    //PRINT CPU FREQUENCY IN MHZ

    uint32_t freq = system_get_cpu_freq();
    os_printf("ESP8266 : SYSINFO : CPU Frequency = %u\n", freq);
}

uint32_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetCpuFrequency(void)
{
    //RETURN CPU FREQUENCY IN MHZ

    uint32_t freq = system_get_cpu_freq();
    return freq;
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSystemMac(void)
{
    //PRINT SYSTEM MAC ADDRESS

    char sys_mac[6];
    wifi_get_macaddr(STATION_IF, sys_mac);
    os_printf("ESP8266 : SYSINFO : System MAC : %02X:%02X:%02X:%02X:%02X:%02X:\n", sys_mac[0], sys_mac[1], sys_mac[2], sys_mac[3], sys_mac[4], sys_mac[5]);
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSystemMac(uint8_t* mac)
{
    //RETURN SYSTEM MAC ADDRESS

    wifi_get_macaddr(STATION_IF, mac);
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintESP8266ChipId(void)
{
    //PRINT ESP8266 CHIP ID

    os_printf("ESP8266 : SYSINFO : Esp8266 Chip Id : 0x%X\n", system_get_chip_id());
}

uint64_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetESP8266ChipId(void)
{
    //RETURN ESP8266 CHIP ID

    return system_get_chip_id();
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintSDKVersion(void)
{
    //PRINT SDK VERSION

    os_printf("ESP8266 : SYSINFO : SDK Version : %s\n", system_get_sdk_version());
}

const char* ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetSDKVersion(void)
{
    //RETURN SDK VERSION

    return system_get_sdk_version();
}

void ICACHE_FLASH_ATTR ESP8266_SYSINFO_PrintResetDetails(void)
{
    //PRINT SYSTEM RESET DETIALS

    struct rst_info* r_reason = NULL;

    if((r_reason = system_get_rst_info()) != NULL)
    {
        switch(r_reason->reason)
        {
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

struct rst_info* ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetResetDetails(void)
{
    //PRINT SYSTEM RESET DETIALS

    struct rst_info* r_reason = system_get_rst_info();
    return r_reason;
}

uint8_t ICACHE_FLASH_ATTR ESP8266_SYSINFO_GetCRC8(char* data, uint16_t len)
{
		//RETURN CRC8 CHECKSUM OF THE SUPPLIED DATA WITH SPECIFIED LENGTH

    char crc = 0x00;
    char extract, sum;
    uint16_t i;
    uint8_t j;

    for(i = 0; i < len; i++)
    {
       extract = *data;
       for (j = 8; j > 0; j--)
       {
          sum = (crc ^ extract) & 0x01;
          crc >>= 1;
          if(sum)
             crc ^= 0x8C;
          extract >>= 1;
       }
       data++;
    }
    return crc;
}
