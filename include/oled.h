#pragma once

#include <Arduino.h>

struct OLEDInputData
{
    int rssi;
    int rx;
    int tx;
    float batteryVoltage;
    int batteryPercentage;
    float lat;
    float lon;
    float alt;
    float targetLat;
    float targetLon;
    float targetAlt;
};

void OLEDInit();
void OLEDUpdateScreen(OLEDInputData &data);
void _OLEDDrawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress);
void _OLEDDrawCompass(uint16_t x, uint16_t y, float angle, float pitch, float roll);
void _OLEDDrawBatteryIndicator(uint16_t x, uint16_t y, uint16_t width, uint16_t height, int percentage);