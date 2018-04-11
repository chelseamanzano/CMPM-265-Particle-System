#pragma once

#include "Behavior.h"

using namespace std;

class LinearBehavior : public Behavior {
public:
	virtual float behavior_at_time(float fraction, float currLifetime, float maxLifetime);
};