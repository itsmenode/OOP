#include "Volvo.h"

void Volvo::Set() {
	capacity = 20.0f;
	consumtion = 5.0f;
	avg_speed_rain = 50;
	avg_speed_sunny = 75;
	avg_speed_snow = 40;
}

std::string Volvo::getName() const {
	return name;
}