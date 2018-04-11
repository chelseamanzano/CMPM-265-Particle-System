#include "LinearBehavior.h"

float LinearBehavior::behavior_at_time(float fraction, float currLifetime, float maxLifetime) {
	return currLifetime + ((maxLifetime - currLifetime)/maxLifetime) * fraction;
}