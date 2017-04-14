#include "WC_FSM.h"
#include "WC_RTC.h"
#include "CRC16.h"
#include "WC_CONFIG.h"
#include "WC_EEPROM.h"
#include "WC_DEBUG.h"

#include <WiFiManager.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>

const int LDR = A0;
const int BUTTON = 4;
const int RED = 15;
const int GREEN = 12;
const int BLUE = 13;

void setup()
{
	DEBUG_INIT()
    DEBUG_PRINTF("\n\nFree memory %d\n", ESP.getFreeHeap())

	configurePins();
	readSettings();

	if (digitalRead(BUTTON) == LOW) {
		WiFiManager wifiManager;
		
		WiFiManagerParameter custom_text("<p>This is just a text paragraph</p>");
		wifiManager.addParameter(&custom_text);

		if (!wifiManager.startConfigPortal("OnDemandAP")) {
			Serial.println("failed to connect and hit timeout");
			delay(3000);
			//reset and try again, or maybe put it to deep sleep
			ESP.reset();
			delay(5000);
		}
	}

	switch (FSMState)
	{
	case STATE_UNDEFINED:
		//if (WC_RTC.initialized == false)
		break;
	case STATE_COLD_RESTART:
		//TODO: close valves!!!
		break;
	case STATE_WIFI_AP_MODE:
		break;
	case STATE_JUMPING:
		break;
	case STATE_DUCKING:
		break;
	case STATE_DIVING:
		break;
	default:
		break;
	}
}

void configurePins() {
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);

	pinMode(BUTTON, INPUT);

}

void readSettings() {
	WC_EEPROM.begin();
	WC_RTC.begin();

	WC_EEPROM.read();
	WC_RTC.read();
}

void loop()
{

	/* add main program code here */
	delay(1000);
}
