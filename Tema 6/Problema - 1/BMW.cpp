#include "BMW.h"

void BMW::Set() {
	capacity = 60.0f;
	consumtion = 23.0f;
	avg_speed_rain = 85;
	avg_speed_sunny = 160;
	avg_speed_snow = 65;
}

std::string BMW::getName() const {
	return name;
}