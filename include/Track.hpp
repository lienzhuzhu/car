/*
 * Track class declaration
 */

#ifndef TRACK_HPP
#define TRACK_HPP

#include <raylib/raylib.h>


#define NUM_POINTS  5
#define MIN_LENGTH  20
#define MAX_LENGTH  50


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
