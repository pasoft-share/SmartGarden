// 
// 
// 

#include "WC_RTC.h"

void WC_RTCClass::begin()
{


}

void WC_RTCClass::write()
{
}

bool WC_RTCClass::initialized()
{
	return RTCVar.magic != RTC_MAGIC;
}


struct RTCStruct RTCVar;
WC_RTCClass WC_RTC;

