#include <Eigen/Dense>
#include <iostream>
#include <raylib/raylib.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   800


int main(void)
{
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

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
