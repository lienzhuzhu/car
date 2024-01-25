/* 
 * Car class declaration
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <raylib/raylib.h>
#include "Track.hpp"

#define CAR_WIDTH   30.f
#define CAR_LENGTH  60.f

class Car {
public:
    Car() = default;
    Car(Track *track);
    Car(Car &&) = default;
    Car(const Car &) = default;
    Car &operator=(Car &&) = default;
    Car &operator=(const Car &) = default;
    ~Car() = default;

    void control(void);
    void set_prev_state(void);
    void update(double dt);
    void render(float remain);
    Vector2 get_center(void);
    double get_fitness(void);

private:
    typedef struct {
        float  x;
        float  y;
        double  speed;
        double  acceleration;
        double  max_speed;
        float   steering_angle;
        float   steering_rate;
    } Car_State;

    Track *_track;
    Car_State _curr_state;
    Car_State _prev_state; // for render interpolation
    Rectangle _body;
    Color _color;
};


#endif // !CAR_HPP
