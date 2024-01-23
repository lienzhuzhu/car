/*
 * Car class definition
 */


#include "Car.hpp"
#include <raylib.h>
#include <raylib/raylib.h>


Car::Car(Track *track) : _color(RED), _track(track)
{
    _body = { 
        .x = GetScreenWidth()/2.f - CAR_WIDTH/2.f,
        .y = GetScreenHeight()/2.f - CAR_LENGTH/2.f,
        .width = CAR_WIDTH,
        .height = CAR_LENGTH
    };

    _curr_state = {
        .center = {
            CAR_WIDTH/2.f,
            CAR_LENGTH/2.f
        },
        .steering_angle = 0.f
    };

    set_prev_state();
}

Vector2 Car::get_center()
{
    return _curr_state.center;
}

void Car::render(double remainder)
{
    DrawRectanglePro(_body, _curr_state.center, _curr_state.steering_angle, _color);
}

void Car::set_prev_state()
{
    _prev_state = _curr_state;
}
