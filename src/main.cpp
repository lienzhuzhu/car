/*
 * Driver code
 */

#include <chrono>
#include <raylib.h>

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

    Camera2D camera = { 0 };
    camera.target = (Vector2){ ball.get_position().x, ball.get_position().y };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while ( !WindowShouldClose() )
    {
        std::chrono::time_point curr_time_point = std::chrono::high_resolution_clock::now();
        double frame_time = std::chrono::duration<double>(curr_time_point - prev_time_point).count();
        if (frame_time > 1.f/MIN_FPS) {
            frame_time = 1.f/MIN_FPS;
        }
        prev_time_point = curr_time_point;

        accumulator += frame_time;

        Vector2 direction = get_direction();

        while ( accumulator >= dt )
        {
            ball.set_prev_state();
            ball.update(direction, 100.f, dt);
            accumulator -= dt;
        }

        camera.target = (Vector2){ ball.get_position().x, ball.get_position().y };

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                DrawRectangleV({10.f, 10.f}, {10.f, 10.f}, RED);
                DrawRectangleV({GetScreenWidth()-20.f, 10.f}, {10.f, 10.f}, BLUE);
                DrawRectangleV({10.f, GetScreenHeight()-20.f}, {10.f, 10.f}, BLUE);
                DrawRectangleV({GetScreenWidth()-20.f, GetScreenHeight()-20.f}, {10.f, 10.f}, RED);

                ball.render(accumulator / dt);

            EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
