// 
// 
// 

#include "WC_EEPROM.h"
#include "WC_CONFIG.h"
#include "WC_DEBUG.h"
#include "CRC16.h"

#define WC_EEPROM_SIZE WC_CONFIG_SIZE + sizeof(ConfigCRC)

uint16_t WC_EEPROMClass::getCRC()
{
	uint16_t crc = CRC16.getCRC(WC_Config);
	DEBUG_PRINTF("CRC=%d\n", crc);
	return  crc;
}

void WC_EEPROMClass::begin()
{
	EEPROM.begin(WC_EEPROM_SIZE);
	DEBUG_PRINTF("EEPROM init. Size = %d\n", (int)WC_EEPROM_SIZE);
}

void WC_EEPROMClass::read()
{
	uint16_t vRomCRC;
	EEPROM.get(0, WC_Config);
	EEPROM.get(WC_CONFIG_SIZE, vRomCRC);

	uint16_t vCRC = getCRC();
	if (vRomCRC == vCRC) {
		DEBUG_PRINTF("EEPROM Config is correct (%d)\n", vCRC);
	}
	else {
		DEBUG_PRINTF("EEPROM CRC (%d) is not correct. Should be %d\n", vRomCRC, vCRC);
		reset();
		save();
	}
}

void WC_EEPROMClass::save()
{
	uint16_t crc = getCRC();
	EEPROM.put(0, WC_Config);
	EEPROM.put(WC_CONFIG_SIZE, crc);
	EEPROM.commit();

	DEBUG_PRINTF("Config saved to EEPROM (%d)\n", crc);
}

void WC_EEPROMClass::reset()
{
	memset(&WC_Config, '\0', WC_CONFIG_SIZE);
	//   for( int i=0, byte *p = (byte *)&WC_Config; i<sz1; i++, p++) 
	//       *p = 0;   

	strcpy(WC_Config.ESP_NAME, "SmartHome_Cooler1");
	strcpy(WC_Config.ESP_PASS, "admin");
	strcpy(WC_Config.AP_SSID, "none");
	strcpy(WC_Config.AP_PASS, "");
	WC_Config.IP[0] = 192;
	WC_Config.IP[1] = 168;
	WC_Config.IP[2] = 1;
	WC_Config.IP[3] = 4;
	WC_Config.MASK[0] = 255;
	WC_Config.MASK[1] = 255;
	WC_Config.MASK[2] = 255;
	WC_Config.MASK[3] = 0;
	WC_Config.GW[0] = 192;
	WC_Config.GW[1] = 168;
	WC_Config.GW[2] = 1;
	WC_Config.GW[3] = 1;
	strcpy(WC_Config.NTP_SERVER1, "0.ru.pool.ntp.org");
	strcpy(WC_Config.NTP_SERVER2, "1.ru.pool.ntp.org");
	strcpy(WC_Config.NTP_SERVER3, "2.ru.pool.ntp.org");
	WC_Config.TZ = 5;
	WC_Config.LIGHT_LIMIT = 900;
	WC_Config.TIMEOUT_CHANGE_HUM = 60000;
	WC_Config.TIMEOUT_DISPLAY = 5000;
	WC_Config.TIMEOUT_NTP = 600000;
	WC_Config.TIMER_PERIOD = 1200;
	WC_Config.HUM_DELTA = 3;
	WC_Config.HUM_MAXIMUM = 85;
	WC_Config.TIMEOUT_SEND1 = 900000;
	WC_Config.TIMEOUT_SEND2 = 60000;
	strcpy(WC_Config.HTTP_SERVER, "service.samopal.pro");
	//   strcpy(WC_Config.HTTP_REQUEST,"/save3?id=%s&h=%d&t=%d&a=%d&tm1=%d&tm2=%d&uptime=%ld");  
}


WC_EEPROMClass WC_EEPROM;

