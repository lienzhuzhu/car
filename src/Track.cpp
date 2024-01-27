/*
 * Track class definition
 */

#include <cstdlib>
#include <ctime>
#include "Track.hpp"
#include "global.hpp"


Track::Track()
{
    generate_guide_points();
}


void Track::generate_guide_points(void)
{
    std::srand(std::time(nullptr));

    float last_angle = 0;
    Vector2 last_point = { SCREEN_CENTER_X, SCREEN_CENTER_Y };

    for (int i = 0; i < NUM_POINTS; ++i) {
        float angle = std::rand() % MAX_ANGLE;
        float distance = (std::rand() % (MAX_LENGTH - MIN_LENGTH)) + MIN_LENGTH;

        if (rand() % 2) {
            last_angle += angle;
        } else {
            last_angle -= angle;
        }

        Vector2 newPoint;
        newPoint.x = last_point.x + cos(last_angle * M_PI / 180.0f) * distance;
        newPoint.y = last_point.y + sin(last_angle * M_PI / 180.0f) * distance;

        _guide_points[i] = newPoint;
        last_point = newPoint;
    }
}

void Track::draw_track(void)
{
    int num_points = sizeof(_guide_points) / sizeof(_guide_points[0]);

    DrawLineStrip(_guide_points, num_points, BLACK); // draws sequence of lines using gl lines
}
