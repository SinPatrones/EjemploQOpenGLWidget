#include "MyUtil.h"

const int displayXYZMin = -100;
const int displayXYZMax = 100;
const int currentRGBMin = 0;
const int currentRGBMax = 255;

float normalize(float value, float min, float max)
{
    // normaliza entre 0 y 1
    const float normalized = (value - min) / (max - min);
    return normalized;
}

float denormalize(float normalized, float min, float max)
{
    // desnormaliza entre 0 y 1
    const float denormalized = (normalized * (max - min) + min);
    return denormalized;
}

float normalize2(float x, float min, float max)
{
    // normaliza entre -1 y 1
    const float normalized = 2.0f * ((x - min) / (max - min)) - 1;
    return normalized;
}

float denormalize2(float normalized, float min, float max)
{
    // desnormaliza entre -1 y 1
    const float denormalized = (normalized + 1) * (max - min) * 0.5f + min;
    return denormalized;
}
