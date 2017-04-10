// CRC16.h

#ifndef _CRC16_h
#define _CRC16_h

#include "arduino.h"

class CRC16Class
{
 protected:
	 uint16_t crc16_update(uint16_t crc, uint8_t a);
 public:
	 template<typename T>
     inline uint16_t getCRC(T &t)
	 {
		 uint16_t crc = 0;
		 size_t sz1 = sizeof(t);
		 for (int i = 0; i < sz1; i++) {
			 crc = crc16_update(crc, *((uint8_t*)&t + i));
		 }

		 return crc;
	 }
};

extern CRC16Class CRC16;

#endif
