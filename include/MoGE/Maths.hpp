#pragma once

namespace momo {

#define PI 3.14159f
#define TWO_PI 6.28318f
float deg2rad(float deg);
float rad2deg(float rad);

float randomf(float min, float max);
float randomf(float max);
float random(float min, float max);
float random(float max);
int randomi(int min, int max);
int randomi(int max);

float constrain(float val, float low, float high);

float interpLin(const float from, const float to, const float t);
float interpLinf(const float from, const float to, const float t);
int interpLini(const int from, const int to, const float t);

float map(float value, float start1, float end1, float start2, float end2,
          bool withinBounds = true);
} // namespace momo
