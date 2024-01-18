#include <Eigen/Dense>
#include <raylib/raylib.h>

#include "constants.h"


int main(void)
{
    SetTraceLogLevel(LOG_WARNING); 

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Evolution Simulation");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
