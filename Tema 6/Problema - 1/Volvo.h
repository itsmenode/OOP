#pragma once
#include "Car.h"

class Volvo : public Car {
private:
	std::string name = "Volvo";
public:
	void Set() override;
	std::string getName() const override;
};