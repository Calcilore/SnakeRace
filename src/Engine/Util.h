#ifndef RAYGINE_UTIL_H
#define RAYGINE_UTIL_H

#include <cmath>
#include "raylib.h"

float MoveToward(float from, float to, float delta);
int sign(float val);
void DrawTextCentered(const char* text, int x, int y, int size, Color color);

#endif //RAYGINE_UTIL_H
