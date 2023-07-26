#ifndef RAYGINE_MAINCAMERA_H
#define RAYGINE_MAINCAMERA_H

#include "raylib.h"
#include "raymath.h"

class MainCamera : public Camera2D {
    public:
        void Update();
};


#endif //RAYGINE_MAINCAMERA_H
