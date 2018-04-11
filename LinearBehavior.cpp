#include "LinearBehavior.h"

float LinearBehavior::behavior_at_time(float minValue, float changeValue, float currLifetime, float maxLifetime) {
	return changeValue*currLifetime/maxLifetime+minValue;
}