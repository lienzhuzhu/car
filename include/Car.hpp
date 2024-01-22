/* 
 * Car class declaration
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <raylib/raylib.h>


class Car {
public:
    Car();
    Car(Car &&) = default;
    Car(const Car &) = default;
    Car &operator=(Car &&) = default;
    Car &operator=(const Car &) = default;
    ~Car() = default;

    void update(Vector2 direction, double velocity, double dt);
    void render(double remainder);
    void set_prev_state(void);
    Vector2 get_center(void);

private:
    typedef struct {
        /* position fields and such */
    } Car_State;

    Car_State _curr_state;
    Car_State _prev_state; // for render interpolation
    Color _color;
};

#endif // !CAR_HPP
