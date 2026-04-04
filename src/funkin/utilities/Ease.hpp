#pragma once

#include "raylib.h"

// header file with missing flixel ease functions
// https://github.com/HaxeFlixel/flixel/blob/master/flixel/tweens/FlxEase.hx

#define ELASTIC_AMPLITUDE 1.0
#define ELASTIC_PERIOD 0.4

#define EASE_IN_ELASTIC [](float x){return -(ELASTIC_AMPLITUDE * pow(2, 10 * (x -= 1)) * sin((x - (ELASTIC_PERIOD / (2 * PI) * asin(1 / ELASTIC_AMPLITUDE))) * (2 * PI) / ELASTIC_PERIOD));}
#define EASE_OUT_ELASTIC [](float x){return (ELASTIC_AMPLITUDE * pow(2,-10 * x) * sin((x - (ELASTIC_PERIOD / (2 * PI) * asin(1 / ELASTIC_AMPLITUDE))) * (2 * PI) / ELASTIC_PERIOD) + 1);}
#define EASE_IN_OUT_ELASTIC [](float x){if (x < 0.5){ return -0.5 * (pow(2, 10 * (x -= 0.5)) * sin((x - (ELASTIC_PERIOD / 4)) * (2 * PI) / ELASTIC_PERIOD));} return pow(2, -10 * (x -= 0.5)) * sin((x - (ELASTIC_PERIOD / 4)) * (2 * PI) / ELASTIC_PERIOD) * 0.5 + 1;}
#define EASE_IN_OUT_SMOOTH_STEP [](float x){return x * x * (x * -2 + 3);}
#define EASE_IN_SMOOTH_STEP [](float x){return 2 * EASE_IN_OUT_SMOOTH_STEP(x / 2);}
#define EASE_OUT_SMOOTH_STEP [](float x){return 2 * EASE_IN_OUT_SMOOTH_STEP(x / 2 + 0.5) - 1;}
#define EASE_IN_OUT_SMOOTHER_STEP [](float x){return x * x * x * (x * (x * 6 - 15) + 10);}
#define EASE_IN_SMOOTHER_STEP [](float x){return 2 * EASE_IN_OUT_SMOOTHER_STEP(x / 2);}
#define EASE_OUT_SMOOTHER_STEP [](float x){return 2 * EASE_IN_OUT_SMOOTHER_STEP(x / 2 + 0.5) - 1;}



