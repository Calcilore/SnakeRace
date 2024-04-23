#include "Engine/MainCamera.h"
#include "Game/World.h"
#include "Engine/Util.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int HALF_WIDTH = WIDTH / 2;
const int HALF_HEIGHT = HEIGHT / 2;
const int SNAKE_COUNT = 2;

MainCamera camera;
World world;
bool paused;

void Draw(float delta);

int main() {
    InitWindow(WIDTH, HEIGHT, "car game");
    SetWindowMinSize(0, 0);
    SetTargetFPS(384); // Set max FPS
    SetExitKey(KEY_NULL);

    paused = false;

    camera = {0};
    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){HALF_WIDTH, HALF_HEIGHT};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.ForceUpdate();

    world = World();

    for (int i = 0; i < SNAKE_COUNT; ++i) {
        Snake* snake = new Snake();
        snake->playerIndex = i;
        snake->world = &world;
        snake->Ready();
        world.snakes.push_back(snake);
    }

    world.Ready();

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();

        // Update
        if (IsKeyPressed(KEY_F)) {
            ToggleFullscreen();
        }

        if (IsKeyPressed(KEY_ESCAPE)) {
            paused = !paused;
        }

        camera.Update();

        if (paused) {
            Draw(delta);
            continue;
        }

        world.Update(delta);

        Draw(delta);
    }

    CloseWindow();
    return 0;
}

void Draw(float delta) {
    BeginDrawing();
    ClearBackground(Color{ 24, 22, 24, 255 });

    BeginMode2D(camera);
        for (int x = -12; x < 12; ++x) {
            for (int y = -12; y < 12; ++y) {
                DrawRectangle(x*32+1, y*32+1, 30, 30, Color{ 32, 32, 32, 255 });
            }
        }

        world.Draw(delta);
        for (Snake* snake : world.snakes) {
            snake->Draw(delta);
        }

        if (paused) {
            DrawTextCentered("Paused", 0, 0, 96, BLUE);
        }
    EndMode2D();

    DrawFPS(10, 10);
    DrawText(TextFormat("Points: %d", world.points), 10, 35, 20, GREEN);
    DrawText(TextFormat("Speed: %d/s", (int)(1.0f / world.speed)), 10, 60, 20, GREEN);

//            DrawText(TextFormat("%f", deltaMultiplier), 10, 40, 20, WHITE);
    EndDrawing();
}
