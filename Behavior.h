#pragma once

using namespace std;

class Behavior {
public:
	virtual float behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime) = 0;
};