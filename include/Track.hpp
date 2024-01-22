/*
 * Track class declaration
 */

#ifndef TRACK_HPP
#define TRACK_HPP

#include <raylib/raylib.h>


class Track {
public:
    Track();
    Track(Track &&) = default;
    Track(const Track &) = default;
    Track &operator=(Track &&) = default;
    Track &operator=(const Track &) = default;
    ~Track() = default;

private:

};

#endif // !TRACK_HPP
