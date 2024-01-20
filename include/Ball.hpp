/* 
 * Ball class declaration
 */

#pragma once

#include <raylib.h>

class Ball {
public:
    Ball();
    Ball(Vector2 position, int radius, Color color);
    Ball(Ball &&) = default;
    Ball(const Ball &) = default;
    Ball &operator=(Ball &&) = default;
    Ball &operator=(const Ball &) = default;
    ~Ball() = default;

    void update(double dt);
    void render(double remainder);
    void set_prev_state(void);

private:
    Vector2 _position;
    int _radius;
    Color _color;
    Vector2 _prev_state;
};
