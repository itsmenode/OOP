#pragma once
#include "Car.h"

class Seat : public Car {
private:
	std::string name = "Seat";
public:
	void Set() override;
	std::string getName() const override;
};