/*
 * Track class definition
 */

#include <cstring>
#include <iostream>
#include <ostream>
#include "Track.hpp"


Track::Track()
{
    generate_guide_points();
}


void Track::generate_guide_points(void)
{
    Vector2 track_points[] = {
        {100, 100},
        {300, 200},
        {350, 300},
        {460, 200},
        {500, 100}
    };

    std::cout << sizeof(track_points) << std::endl;
    memcpy(_guide_points, track_points, sizeof(track_points));
}

void Track::draw_track(void)
{
    int num_points = sizeof(_guide_points) / sizeof(_guide_points[0]);

    DrawLineStrip(_guide_points, num_points, BLACK); // draws sequence of lines using gl lines
}
