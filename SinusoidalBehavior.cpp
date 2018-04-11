#include "SinusoidalBehavior.h"

float SinusoidalBehavior::behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime) {
	return -changeValue * cosf(currLifetime/maxLifetime * (M_PI/2)) + changeValue + minValue;
}