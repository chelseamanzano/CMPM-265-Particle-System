#include "ExponentialBehavior.h"

float ExponentialBehavior::behavior_at_time(float fraction, float currLifetime, float maxLifetime) {
	return currLifetime + powf(maxLifetime - currLifetime, 4) * fraction;
}