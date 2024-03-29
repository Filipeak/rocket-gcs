#include "maths.h"
#include <Arduino.h>

float CalculateGeoDistance(float lat1, float lon1, float lat2, float lon2)
{
    float rlat1 = 3.14f * lat1 / 180.0f;
    float rlat2 = 3.14f * lat2 / 180.0f;
    float theta = lon1 - lon2;
    float rtheta = 3.14f * theta / 180.0f;

    float dist = sin(rlat1) * sin(rlat2) + cos(rlat1) * cos(rlat2) * cos(rtheta);

    dist = acos(dist);
    dist = dist * 180.0f / 3.14f;
    dist = dist * 60.0f * 1.1515f;
    dist = dist * 1.609344f;

    return dist;
}

float CalulateGeoBearing(float lat1, float lon1, float lat2, float lon2)
{
    float dy = lat2 - lat1;
    float dx = cosf(M_PI / 180.0f * lat1) * (lon2 - lon1);
    float angle = atan2f(dy, dx);

    angle = angle * 180.0f / 3.14f;
    angle = angle - 90.0f;

    if (angle > 180.0f)
        angle = angle - 360.0f;

    return angle;
}

uint16_t crc16_mcrf4xx_calculate(const uint8_t *data, size_t length)
{
    uint16_t crc = 0xFFFF;
    uint8_t t;
    uint8_t L;

    while (length--)
    {
        crc ^= *data++;
        L = crc ^ (crc << 4);
        t = (L << 3) | (L >> 5);
        L ^= (t & 0x07);
        t = (t & 0xF8) ^ (((t << 1) | (t >> 7)) & 0x0F) ^ (uint8_t)(crc >> 8);
        crc = (L << 8) | t;
    }

    return crc;
}