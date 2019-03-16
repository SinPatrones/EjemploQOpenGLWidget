#ifndef MYUTIL_H
#define MYUTIL_H

extern const int displayXYZMin;
extern const int displayXYZMax;
extern const int currentRGBMin;
extern const int currentRGBMax;

float normalize(float value, float min, float max);
float denormalize(float normalized, float min, float max);

float normalize2(float x, float min, float max);
float denormalize2(float normalized, float min, float max);

#endif // MYUTIL_H
