#include <custom.h>
#include <Arduino.h>
#include <Adafruit_MCP23X17.h>
Adafruit_MCP23X17 mcp[4];
uint8_t address[] = {0x20, 0x27, 0x26, 0x24};
void initializeGPIOExpander()
{
    for (uint8_t i = 0; i < 4; i++)
    {
        if (mcp[i].begin_I2C(address[i]))
        {
            ESP_LOGI("I2C device Connected at %d", address[i]);
        }
        else if (!mcp[i].begin_I2C(address[i]))
        {
            ESP_LOGI(log, "Error at address %d", address[i]);
        }
    }
}

void configGPIO()
{
    ESP_LOGI(log, "Output Configuration:");
    for (uint8_t i = 0; i < 2; i++)
    {
        for (uint8_t j = 0; j < 16; j++)
        {
            mcp[i].pinMode(j, OUTPUT);
            ESP_LOGI(log, "mcp:%d GPIO:%d is set to OUTPUT", i, j);
        }
    }
    ESP_LOGI(log, "Input Configuration:");
    for (uint8_t i = 2; i < 4; i++)
    {
        for (uint8_t j = 0; j < 16; j++)
        {
            mcp[i].pinMode(j, INPUT_PULLUP);
            ESP_LOGI(log, "mcp:%d GPIO:%d is set to INPUT_PULLUP", i, j);
        }
    }
}