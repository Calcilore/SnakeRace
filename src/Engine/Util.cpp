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

void DrawTextCentered(const char *text, int x, int y, int size, Color color) {
    Vector2 siz = MeasureTextEx(GetFontDefault(), text, size, 1);
    DrawText(text, x - (int)siz.x / 2, y - (int)siz.y / 2, size, color);
}
