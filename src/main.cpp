/*
 * Driver code
 */

#include <chrono>

#include "global.hpp"
#include "Ball.hpp"


int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Evolution Simulation");

    double dt = 1.f / TARGET_FPS;
    std::chrono::time_point prev_time_point = std::chrono::high_resolution_clock::now();
    double accumulator = 0.0;

    Ball ball;

    while ( !WindowShouldClose() )
    {
        std::chrono::time_point curr_time_point = std::chrono::high_resolution_clock::now();
        double frame_time = std::chrono::duration<double>(curr_time_point - prev_time_point).count();
        if (frame_time > 1.f/MIN_FPS) {
            frame_time = 1.f/MIN_FPS;
        }
        prev_time_point = curr_time_point;

        accumulator += frame_time;

        while ( accumulator >= dt )
        {
            ball.set_prev_state();
            ball.update(dt);
            accumulator -= dt;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        ball.render(accumulator / dt);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
