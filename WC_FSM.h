// WC_FSM.h

#ifndef _WC_FSM_h
#define _WC_FSM_h

#include "arduino.h"

typedef enum FSMStateEnum
{
	STATE_UNDEFINED = 0,
	STATE_COLD_RESTART,
	STATE_WIFI_AP_MODE,
	STATE_JUMPING,
	STATE_DUCKING,
	STATE_DIVING
};

class WFMan : WiFiManager {

};

extern enum FSMStateEnum FSMState;

#endif

