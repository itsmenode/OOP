#pragma once

#include <iostream>
#include <algorithm>

#include "Car.h"
#include "Volvo.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Fiat.h"
#include "BMW.h"
#include "Weather.h"

class Circuit {
private:
	int length;
	Weather track_conditions;
	int amountCars, dnf;
	Car* Cars[100];
	int times[100];
public:
	Circuit() { amountCars = 0; dnf = 0; }
	void SetLength(int x);
	void SetWeather(Weather x);
	void AddCar(Car* new_car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};