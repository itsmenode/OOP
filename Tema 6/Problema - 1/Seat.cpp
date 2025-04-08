#include "Seat.h"

void Seat::Set() {
	capacity = 12.0f;
	consumtion = 3.0f;
	avg_speed_rain = 35;
	avg_speed_sunny = 60;
	avg_speed_snow = 30;
}

std::string Seat::getName() const {
	return name;
}