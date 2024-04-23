#include "MainCamera.h"

const Vector2 defaultSize = { 800, 800 };

void MainCamera::Update() {
    if (IsWindowResized()) {
        ForceUpdate();
    }
}

void MainCamera::ForceUpdate() {
    Vector2 screenSize = { (float)GetRenderWidth(), (float)GetRenderHeight() };
    offset = Vector2Scale(screenSize, 0.5f);

    // change zoom to fit the screen
    float zoomX = screenSize.x / defaultSize.x;
    float zoomY = screenSize.y / defaultSize.y;
    zoom = fminf(zoomX, zoomY);
}
