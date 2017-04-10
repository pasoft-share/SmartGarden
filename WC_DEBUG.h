// WC_DEBUG.h

#ifndef _WC_DEBUG_h
#define _WC_DEBUG_h

#include "arduino.h"

// Uncomment to enable printing out nice debug messages.
#define WC_DEBUG

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef WC_DEBUG
#define DEBUG_INIT(...) { DEBUG_PRINTER.begin(115200); }
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTF(...) { DEBUG_PRINTER.printf(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_INIT(...) {}
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTF(...) {}
#define DEBUG_PRINTLN(...) {}
#endif

#endif

