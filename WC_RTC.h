// WC_RTC.h

#ifndef _WC_RTC_h
#define _WC_RTC_h

#include "arduino.h"

#define RTC_MAGIC 0x75a78fc5

typedef struct {
	uint32 magic;
	uint64 calibration;
	float weight;
	boolean battwarningsent;
	boolean weightwarningsent;
} RTC;

class WC_RTCClass
{
protected:
public:
	void begin();
	void write();
	bool initialized();
};

extern RTCStruct RTCVar;

extern WC_RTCClass WC_RTC;

#endif

