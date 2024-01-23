/*
 * Driver code
 */


#include <chrono>
#include <raylib.h>

#include "global.hpp"
#include "Car.hpp"
#include "Track.hpp"


void draw_guides()
{
    DrawRectangleV({10.f, 10.f}, {10.f, 10.f}, RED);
    DrawRectangleV({GetScreenWidth()-20.f, 10.f}, {10.f, 10.f}, BLUE);
    DrawRectangleV({10.f, GetScreenHeight()-20.f}, {10.f, 10.f}, BLUE);
    DrawRectangleV({GetScreenWidth()-20.f, GetScreenHeight()-20.f}, {10.f, 10.f}, RED);

    DrawLineV({SCREEN_CENTER_X, 0}, {SCREEN_CENTER_X, GetScreenHeight()*1.f}, BLACK);
    DrawLineV({0, SCREEN_CENTER_Y}, {GetScreenWidth()*1.f, SCREEN_CENTER_Y}, BLACK);
}

int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Evolution Simulation");


    double dt = 1.f / TARGET_FPS;
    std::chrono::time_point prev_time_point = std::chrono::high_resolution_clock::now();
    double accumulator = 0.0;

    Track track;
    Car car(&track);

    Camera2D camera = { 0 };
    
    camera.target = car.get_center();
    camera.offset = (Vector2){ GetScreenWidth()/2.f, GetScreenHeight()/2.f };
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


        car.control();


        while ( accumulator >= dt )
        {
            car.update(dt);

            accumulator -= dt;
        }

        camera.target = car.get_center();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                draw_guides();
                car.render(accumulator / dt);

            EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
