#include "Fiat.h"

void Fiat::Set() {
	capacity = 12.0f;
	consumtion = 13.0f;
	avg_speed_rain = 37;
	avg_speed_sunny = 62;
	avg_speed_snow = 35;
}

std::string Fiat::getName() const {
	return name;
}
