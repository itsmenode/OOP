#pragma once
#include "Car.h"

class Fiat : public Car {
private:
	std::string name = "Fiat";
public:
	void Set() override;
	std::string getName() const override;
};