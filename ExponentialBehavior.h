#pragma once

#include "Behavior.h"
#include <math.h>

using namespace std;


class ExponentialBehavior : public Behavior {
public:
	virtual float behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime);
};