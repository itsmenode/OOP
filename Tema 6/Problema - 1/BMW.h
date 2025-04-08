#pragma once
#include "Car.h"

class BMW :public Car {
private:
	std::string name = "BMW";
public:
	void Set() override;
	std::string getName() const override;
};