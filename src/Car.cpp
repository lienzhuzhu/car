/*
 * Car class definition
 */

#include <cmath>
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
        .x = SCREEN_CENTER_X,
        .y = SCREEN_CENTER_Y,
        .speed = 0.f,
        .acceleration = ACCELERATION_RATE,
        .max_speed = MAX_SPEED,
        .steering_angle = 0.f,
        .steering_rate = STEERING_RATE
    };

    _body = { 
        .x = _curr_state.x, // NOTE: start the car in the center of the screen for now
        .y = _curr_state.y,
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
        _curr_state.speed -= _curr_state.acceleration;
    }
    if (IsKeyDown(KEY_DOWN)) {
        _curr_state.speed += _curr_state.acceleration;
    }

    if (IsKeyDown(KEY_LEFT)) {
        _curr_state.steering_angle -= _curr_state.steering_rate;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        _curr_state.steering_angle += _curr_state.steering_rate;
    }

    if (_curr_state.speed > _curr_state.max_speed) {
        _curr_state.speed = _curr_state.max_speed;
    }
    if (_curr_state.speed < -_curr_state.max_speed) {
        _curr_state.speed = -_curr_state.max_speed;
    }
}

void Car::update(double dt)
{
    set_prev_state();

    // NOTE:    sinf() and cosf() are switched from their usual coordinate associations because 
    //          I consider the long side aligned with the y axis as the 0 degree orientation 
    //          while raylib considers the +x ray to be the 0 degree vector.
    _curr_state.x -= _curr_state.speed * dt * sinf(DEG2RAD * _curr_state.steering_angle);
    _curr_state.y += _curr_state.speed * dt * cosf(DEG2RAD * _curr_state.steering_angle);
    _body.x = _curr_state.x;
    _body.y = _curr_state.y;
}

void Car::render(float remain)
{
    float rendered_angle = _prev_state.steering_angle + remain * (_curr_state.steering_angle - _prev_state.steering_angle);

    Rectangle rendered_body = _body;
    rendered_body.x = _prev_state.x + remain * (_curr_state.x - _prev_state.x);
    rendered_body.y = _prev_state.y + remain * (_curr_state.y - _prev_state.y);

    Vector2 render_origin = {CAR_WIDTH/2.f, CAR_LENGTH/2.f}; // NOTE: even though the _body Rectangle 
                                                             // specifies top left corner, setting 
                                                             // center in DrawRectanglePro() draws 
                                                             // outward from that center

    DrawRectanglePro(_body, render_origin, rendered_angle, _color);
}
