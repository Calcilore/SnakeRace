#include "Util.h"

using namespace std;

float MoveToward(float from, float to, float delta) {
    if (from < to) {
        return fminf(from + delta, to);
    } else {
        return fmaxf(from - delta, to);
    }
}

int sign(float val) {
    return (float(0) < val) - (val < float(0));
}

float randf(float max) {
    return float(rand()) / float((RAND_MAX)) * max;
}

void DrawTextCentered(const char *text, float x, float y, float size, Color color) {
    Vector2 siz = MeasureTextEx(GetFontDefault(), text, size, 1);
    DrawTextEx(GetFontDefault(), text, {x - siz.x / 2, y - siz.y / 2}, size, 1, color);
}
