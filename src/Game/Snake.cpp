#include "Snake.h"

void Snake::Ready() {
    body.emplace_front(-2, playerIndex * 2 - 4);
    body.emplace_front(-1, playerIndex * 2 - 4);
    body.emplace_front(0, playerIndex * 2 - 4);
    body.emplace_front(1, playerIndex * 2 - 4);
    body.emplace_front(2, playerIndex * 2 - 4);

    direction = Vec2I{1,0};
}

void Snake::Update(float delta) {
    // get input
    Vec2I newDirection;
    newDirection.x = IsKeyPressed(KEYS[playerIndex][0]) - IsKeyPressed(KEYS[playerIndex][1]);
    newDirection.y = newDirection.x == 0 ? IsKeyPressed(KEYS[playerIndex][2]) - IsKeyPressed(KEYS[playerIndex][3]) : 0;

    if (newDirection.x != 0 || newDirection.y != 0) {
        Vec2I oldDirection = direction;
        if (!inputs.empty()) {
            oldDirection = inputs.back();
        }

        if (newDirection != oldDirection * -1 && newDirection != oldDirection) {
            inputs.push_back(newDirection);
        }
    }
}

void Snake::Move() {
    // if there is an input, use it
    if (!inputs.empty()) {
        direction = inputs.front();
        inputs.pop_front();
    }

    // calculate new position, including wrapping around the screen
    Vec2I newPos = body.front() + direction;
    if (newPos.x > 11) newPos.x = -12;
    else if (newPos.x < -12) newPos.x = 11;
    else if (newPos.y > 11) newPos.y = -12;
    else if (newPos.y < -12) newPos.y = 11;

    // check if we hit ourselves or another snake
    for (Snake* snake : world->snakes) {
        if (World::contains(snake->body, newPos)) {
            world->End();
            return;
        }
    }

    // check if we hit an apple
    bool grow = false;
    if (World::contains(world->apples, newPos)) {
        world->SpawnApple();
        world->apples.remove(newPos);

        ++world->points;
        grow = true;
    }

    // move the snake, and remove the last segment if we didn't eat an apple
    body.push_front(newPos);
    if (!grow) {
        body.pop_back();
    }
}

void Snake::Draw(float delta) {
    for (Vec2I& part : body) {
        DrawRectangleV((part * 32 + 1).ToVector2(), { 30, 30 }, SNAKE_COLORS[playerIndex]);
    }
}

void Snake::Reset() {
    body.clear();
    inputs.clear();
    Ready();
}
