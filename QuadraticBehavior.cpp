#include "QuadraticBehavior.h"

float QuadraticBehavior::behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime) {
	currLifetime /= maxLifetime;
	return changeValue * currLifetime * currLifetime  + minValue;
}