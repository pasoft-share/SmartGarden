#include "WC_RTC.h"
#include "CRC16.h"
#include "WC_CONFIG.h"
#include "WC_EEPROM.h"
#include "WC_DEBUG.h"

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>

void setup()
{
	DEBUG_INIT()
	DEBUG_PRINTF("\n\nFree memory %d\n", ESP.getFreeHeap())

	initialize();
}

void initialize() {

	WC_EEPROM.begin();
	WC_RTC.begin();

	WC_EEPROM.read();
}

void loop()
{

	/* add main program code here */
	delay(1000);
}
