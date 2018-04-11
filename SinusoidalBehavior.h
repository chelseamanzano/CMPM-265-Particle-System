#pragma once
#define _USE_MATH_DEFINES
#include "Behavior.h"
#include <iostream>
#include <math.h>

using namespace std;


class SinusoidalBehavior : public Behavior {
public:
	virtual float behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime);
};