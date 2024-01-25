/*
 * Car class definition
 */

#include <raylib.h>
#include <raylib/raylib.h>
#include "global.hpp"
#include "Car.hpp"


#define ACCELERATION_RATE   0.5f
#define MAX_SPEED           600.f
#define STEERING_RATE       0.05f


Car::Car(Track *track) : _color(RED), _track(track)
{
    _curr_state = {
        .speed = 0.f,
        .acceleration = ACCELERATION_RATE,
        .max_speed = MAX_SPEED,
        .steering_angle = 0.f,
        .steering_rate = STEERING_RATE
    };

    _body = { 
        .x = SCREEN_CENTER_X, // NOTE: start the car in the center of the screen for now
        .y = SCREEN_CENTER_Y,
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

void Car::control()
{
    /* handle input */
    if (IsKeyDown(KEY_UP)) {
        _curr_state.speed -= ACCELERATION_RATE;
    }
    if (IsKeyDown(KEY_DOWN)) {
        _curr_state.speed += ACCELERATION_RATE;
    }

    if (IsKeyDown(KEY_LEFT)) {
        _curr_state.steering_angle -= STEERING_RATE;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        _curr_state.steering_angle += STEERING_RATE;
    }

    /* clamp speed and rotation? */
    if (_curr_state.speed > MAX_SPEED) {
        _curr_state.speed = MAX_SPEED;
    }
    if (_curr_state.speed < -MAX_SPEED) {
        _curr_state.speed = -MAX_SPEED;
    }


}

void Car::update(double dt)
{
    // NOTE:    sinf() and cosf() are switched from their usual coordinate associations because 
    //          I consider the long side aligned with the y axis as the 0 degree orientation 
    _body.x -= _curr_state.speed * dt * sinf(DEG2RAD * _curr_state.steering_angle);
    _body.y += _curr_state.speed * dt * cosf(DEG2RAD * _curr_state.steering_angle);
}

void Car::render(double remainder)
{
    Vector2 render_origin = {CAR_WIDTH/2.f, CAR_LENGTH/2.f}; // NOTE: even though the _body Rectangle 
                                                             // specifies top left corner, setting 
                                                             // center in DrawRectanglePro() draws 
                                                             // outward from that center
    DrawRectanglePro(_body, render_origin, _curr_state.steering_angle, _color);
}
