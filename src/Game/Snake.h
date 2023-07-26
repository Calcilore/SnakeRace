#ifndef RACE_SNAKE_H
#define RACE_SNAKE_H


#include <list>
#include "../Engine/Vec2I.h"
#include <cstdio>
#include "World.h"

using namespace std;

class World;

const KeyboardKey KEYS[6][4] = {
    {KEY_D, KEY_A, KEY_S, KEY_W},
    {KEY_RIGHT, KEY_LEFT, KEY_DOWN, KEY_UP},
    {KEY_L, KEY_J, KEY_K, KEY_I},
    {KEY_KP_6, KEY_KP_4, KEY_KP_5, KEY_KP_8},
    {KEY_H, KEY_F, KEY_G, KEY_T},
    {KEY_PAGE_DOWN, KEY_PAGE_UP, KEY_END, KEY_HOME}
};

const Color SNAKE_COLORS[6] = {
    {0, 255, 0, 255},
    {255, 0, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {255, 0, 255, 255},
    {0, 255, 255, 255}
};

class Snake {
public:
    list<Vec2I> body;
    list<Vec2I> inputs;
    Vec2I direction;

    World* world;
    int playerIndex = 0;

    void Ready();
    void Update(float delta);
    void Move();
    void Draw(float delta);
    void Reset();
};


#endif //RACE_SNAKE_H
