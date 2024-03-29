/* 
 * Car class declaration
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <raylib/raylib.h>

#define CAR_WIDTH   30.f
#define CAR_LENGTH  60.f
#define NUM_CORNERS 4

class Car {
public:
    Car();
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
    void initialize_corners(void);
    void calculate_corners(void);
    void draw_corners(void);

private:
    typedef struct {
        float  x;
        float  y;
        double  speed;
        double  acceleration;
        double  max_speed;
        float   steering_angle;
        float   steering_rate;
        Vector2 corners[NUM_CORNERS];
    } Car_State;

    Car_State _curr_state;
    Car_State _prev_state; // for render interpolation
    Rectangle _body; // TODO: remove this member
    Color _color;
};


#endif // !CAR_HPP
