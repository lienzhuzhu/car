/*
 * Ball class definition
 */

#include "Ball.hpp"
#include <raylib.h>


Ball::Ball() : _radius(20), _color(RED)
{
    _position = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
}

Ball::Ball(Vector2 position, int radius, Color color)
{
    _position = position;
    _radius = radius;
    _color = color;
}

void Ball::update(Vector2 direction, double velocity, double dt)
{
    _position.x += direction.x * velocity * dt;
    _position.y += direction.y * velocity * dt;
}

void Ball::render(double remainder)
{
    Vector2 rendered_state;
    rendered_state.x = _position.x * remainder + _prev_state.x * (1.f - remainder);
    rendered_state.y = _position.y * remainder + _prev_state.y * (1.f - remainder);
    DrawCircleV(rendered_state, _radius, _color);
}

void Ball::set_prev_state()
{
    _prev_state = _position;
}

Vector2 Ball::get_position()
{
    return _position;
}
