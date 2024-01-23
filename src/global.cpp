/*
 * Global implementations
 */


#include <raylib.h>
#include "global.hpp"


Vector2 get_direction()
{
    Vector2 direction = { 0.f, 0.f };

    if ( IsKeyDown(KEY_RIGHT) ) {
        direction.x += 1.f;
    }
    if ( IsKeyDown(KEY_LEFT) ) {
        direction.x -= 1.f;
    }
    if ( IsKeyDown(KEY_UP) ) {
        direction.y -= 1.f;
    }
    if ( IsKeyDown(KEY_DOWN) ) {
        direction.y += 1.f;
    }

    return direction;
}
