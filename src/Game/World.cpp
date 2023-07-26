#include "World.h"

void World::Ready() {
    SpawnApple();
    SpawnApple();
    SpawnApple();
    SpawnApple();

    // This generates the list of all tiles
//    cout << "{";
//    for (int x = -12; x < 12; ++x) {
//        for (int y = -12; y < 12; ++y) {
//            cout << "{" << x << "," << y << "},";
//        }
//    }
//    cout << "};";
}

void World::Update(float delta) {
    if (IsKeyPressed(KEY_P)) {
        End();
        return;
    }

    if (state == 0) { // ready
        speed = 1.0f / max(1.0f / speed + GetMouseWheelMove(), 1.0f);

        if (IsKeyPressed(KEY_SPACE)) {
            state = 1;
        }
        return;
    }
    else if (state == 2) { // end
        if (IsKeyPressed(KEY_SPACE)) {
            Reset();
        }
        return;
    }

    for (Snake* snake : snakes) {
        snake->Update(delta);
    }

    timer -= delta;
    while (timer <= 0) {
        timer += speed;

        for (Snake* snake : snakes) {
            snake->Move();
        }
    }
}

void World::Draw(float delta) {
    for (Vec2I& apple : apples) {
        DrawRectangleV((apple * 32 + 1).ToVector2(), { 30, 30 }, Color{255, 0, 0, 128});
    }

    if (state == 0) {
        DrawTextCentered("Press SPACE to Start!", 0, 300, 48, GREEN);
    }
    else if (state == 2) {
        DrawTextCentered("You Died!", 0, 300, 48, RED);
    }

    // Debug: Center marked with blue square
    // DrawRectangleV(Vector2{1, 1}, { 30, 30 }, Color{0, 0, 255, 128});
}

void World::SpawnApple() {
    // copy ALL_TILES[] to allTiles
    Vec2I allTiles[24*24];
    std::copy(std::begin(ALL_TILES), std::end(ALL_TILES), std::begin(allTiles));

    for (int i = 0; i < 24*24;) {
        int index = GetRandomValue(0, 24*24);
        Vec2I newPos = allTiles[index];
        allTiles[index] = {INT_MAX, INT_MAX};

        if (newPos.x == INT_MAX) {
            i++;
            continue;
        }

        if (contains(apples, newPos)) {
            continue;
        }

//        for (Snake* snake : snakes) {
//            if (contains(snake->body, newPos)) {
//                continue;
//            }
//        }

        apples.push_front(newPos);
        return;
    }
}

bool World::contains(const list<Vec2I> &vec, const Vec2I &val) {
    for (Vec2I value : vec) {
        if (value == val) {
            return true;
        }
    }

    return false;
}

void World::End() {
    state = 2;
}

void World::Reset() {
    state = 0;
    points = 0;
    apples.clear();

    for (Snake* snake : snakes) {
        snake->Reset();
    }

    Ready();
}

