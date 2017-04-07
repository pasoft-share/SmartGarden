// WC_DEBUG.h

#ifndef _WC_DEBUG_h
#define _WC_DEBUG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// Uncomment to enable printing out nice debug messages.
#define WC_DEBUG

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef WC_DEBUG
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTF(...) { DEBUG_PRINTER.printf(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTF(...) {}
#define DEBUG_PRINTLN(...) {}
#endif

#endif

