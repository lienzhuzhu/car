/*
 * Car class definition
 */

#include <raylib/raylib.h>
#include "global.hpp"
#include "Car.hpp"


Car::Car(Track *track) : _color(RED), _track(track)
{
    _curr_state = {
        .center = {
            SCREEN_CENTER_X,
            SCREEN_CENTER_Y
        },
        .steering_angle = 45.f
    };

    _body = { 
        .x = _curr_state.center.x, // NOTE: start the car in the center of the screen for now
        .y = _curr_state.center.y,

        .width = CAR_WIDTH,
        .height = CAR_LENGTH
    };


    set_prev_state();
}

Vector2 Car::get_center()
{
    return { _body.x, _body.y };
}

void Car::set_prev_state()
{
    _prev_state = _curr_state;
}

void Car::update(double dt)
{
    /* move the center according to velocity and steering angle */
}

void Car::render(double remainder)
{
    Vector2 render_origin = {CAR_WIDTH/2.f, CAR_LENGTH/2.f}; // NOTE: even though the _body Rectangle 
                                                             // specifies top left corner, setting 
                                                             // center in DrawRectanglePro() draws 
                                                             // outward from that center
    DrawRectanglePro(_body, render_origin, _curr_state.steering_angle, _color);
}
