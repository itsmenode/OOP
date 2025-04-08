#pragma once
#include "Car.h"

class RangeRover : public Car {
private:
	std::string name = "RangeRover";
public:
	void Set() override;
	std::string getName() const override;
};