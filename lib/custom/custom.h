#ifndef custom_h
#define custom_h
#define log "log"
#include <Arduino.h>
#include <Adafruit_MCP23X17.h>
Adafruit_MCP23X17 mcp[];
uint8_t address[];
void initializeGPIOExpander();
void configGPIO();

#endif