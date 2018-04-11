#include "ExponentialBehavior.h"

float ExponentialBehavior::behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime) {
	return changeValue * pow(2, 10*(currLifetime/maxLifetime -1)) + minValue;
}