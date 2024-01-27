/*
 * Track class declaration
 */

#ifndef TRACK_HPP
#define TRACK_HPP

#include <raylib/raylib.h>


#define NUM_POINTS  30
#define MIN_LENGTH  200
#define MAX_LENGTH  500
#define MAX_ANGLE   90


class Track {
public:
    Track();
    Track(Track &&) = default;
    Track(const Track &) = default;
    Track &operator=(Track &&) = default;
    Track &operator=(const Track &) = default;
    ~Track() = default;

    void generate_guide_points(void);
    void draw_track(void);

private:
    Vector2 _guide_points[NUM_POINTS];
};


#endif // !TRACK_HPP
