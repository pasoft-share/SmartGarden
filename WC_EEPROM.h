// EC_EEPROM.h
#ifndef _EC_EEPROM_h
#define _EC_EEPROM_h

#include "arduino.h"

typedef uint16_t ConfigCRC;

class WC_EEPROMClass
{
private:
	uint16_t getCRC();
	void reset();
public:
	void begin();
	void read();
	void save();
};

extern WC_EEPROMClass WC_EEPROM;

#endif

