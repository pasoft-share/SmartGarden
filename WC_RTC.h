// WC_RTC.h

#ifndef _WC_RTC_h
#define _WC_RTC_h

#include "arduino.h"

#define RTC_MAGIC 0x75a7

typedef struct RTCStruct {
	uint16_t magic;

	uint64 calibration;
	float weight;
	boolean battwarningsent;
	boolean weightwarningsent;
};

class WC_RTCClass
{
protected:
public:
	void begin();
	void read();
	void write();
	bool initialized();
};

extern RTCStruct RTCVar;

extern WC_RTCClass WC_RTC;

#endif

