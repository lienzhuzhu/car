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
    Vector2 get_position(void);

private:
    Vector2 _position;
    int _radius;
    Color _color;
    Vector2 _prev_state;
};

#endif // !CAR_HPP
