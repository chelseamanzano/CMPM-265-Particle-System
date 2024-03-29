#pragma once

#include "Behavior.h"
#include <iostream>

using namespace std;


class LinearBehavior : public Behavior {
public:
	virtual float behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime);
};