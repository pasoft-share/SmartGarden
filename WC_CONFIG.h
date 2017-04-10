// WC_CONFIG.h

#ifndef _WC_CONFIG_h
#define _WC_CONFIG_h

#include "arduino.h"

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>

#define WC_CONFIG_SIZE sizeof(WC_Config)

extern struct WC_ConfigStruct WC_Config;

struct WC_ConfigStruct {
	// Наименование в режиме точки доступа  
	char ESP_NAME[32];
	char ESP_PASS[32];
	// Параметры подключения в режиме клиента
	char AP_SSID[32];
	char AP_PASS[32];
	IPAddress IP;
	IPAddress MASK;
	IPAddress GW;
	// Параметры NTP сервера
	char NTP_SERVER1[32];
	char NTP_SERVER2[32];
	char NTP_SERVER3[32];
	short int  TZ;
	// Параметры работы вентилятора 
	// Значение АЦП для срабатывания состояния света
	uint16_t LIGHT_LIMIT;
	// Интервал проверки изменения влажности, мс
	uint32_t TIMEOUT_CHANGE_HUM;
	// Интервал смены показа дисплея, мс
	uint32_t TIMEOUT_DISPLAY;
	// Интервал опроса NTP
	uint32_t TIMEOUT_NTP;
	// Период работы таймера, сек
	uint16_t TIMER_PERIOD;
	// Изменение владности, при котором запускается вентилятор
	uint16_t HUM_DELTA;
	// Абслолютное зачение влажности при которм запускается таймер
	uint16_t HUM_MAXIMUM;
	// Интервал отправки сообщений на сервер, мс
	uint32_t TIMEOUT_SEND1;
	// Интервал отправки сообщений на сервер при включенном свете или вентиляторе, мс
	uint32_t TIMEOUT_SEND2;
	// Сервер куда отправлять статистику
	char     HTTP_SERVER[48];
	// Строка отправки параметров на сервер
	//   char     HTTP_REQUEST[128];   
};


#endif

