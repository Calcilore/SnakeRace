#ifndef RAYGINE_UTIL_H
#define RAYGINE_UTIL_H

#include <cmath>
#include "raylib.h"

float MoveToward(float from, float to, float delta);
int sign(float val);
float randf(float max);
void DrawTextCentered(const char* text, float x, float y, float size, Color color);

#endif //RAYGINE_UTIL_H
