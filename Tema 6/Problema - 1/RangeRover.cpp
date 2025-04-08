#include "RangeRover.h"

void RangeRover::Set() {
	capacity = 32.0f;
	consumtion = 8.0f;
	avg_speed_rain = 60;
	avg_speed_sunny = 80;
	avg_speed_snow = 45;
}

std::string RangeRover::getName() const {
	return name;
}