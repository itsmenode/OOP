#pragma once
#include <iostream>
#include <string>

class Car {
public:
		float capacity, consumtion;
		int avg_speed_rain, avg_speed_sunny, avg_speed_snow;
		virtual std::string getName() const = 0;
		virtual void Set() = 0;
};