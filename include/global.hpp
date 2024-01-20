#pragma once

#include <raylib.h>
#include <Eigen/Dense>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   800

#define MIN_FPS         10.f
#define TARGET_FPS      240.f

Vector2 get_direction(void);
