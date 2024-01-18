#include <chrono>

#include "global.hpp"


int main(void)
{
    set_raylib_log_level(LOG_WARNING);

    auto start_time = std::chrono::high_resolution_clock::now();

    const float dt = 1.0f / 60.0f;
    float last_timestamp = dt;

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
