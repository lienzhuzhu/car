/*
 * Car class definition
 */

#include <raylib/raylib.h>
#include "global.hpp"
#include "Car.hpp"


Car::Car(Track *track) : _color(RED), _track(track)
{
    _body = { 
        .x = SCREEN_CENTER_X,
        .y = SCREEN_CENTER_Y,
        .width = CAR_WIDTH,
        .height = CAR_LENGTH
    };

    _curr_state = {
        .center = {
            SCREEN_CENTER_X,
            SCREEN_CENTER_Y
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
    DrawRectanglePro(_body, {CAR_WIDTH/2.f, CAR_LENGTH/2.f}, _curr_state.steering_angle, _color);
}

void Car::update(double dt)
{

}

void Car::set_prev_state()
{
    _prev_state = _curr_state;
}
