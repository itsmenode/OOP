#include "Circuit.h"

void Circuit::SetLength(int x) {
	length = x;
}

void Circuit::SetWeather(Weather x) {
	track_conditions = x;
}

void Circuit::AddCar(Car* new_car) {
	amountCars++;
	new_car->Set();
	Cars[amountCars] = new_car;
	times[amountCars] = 0;
}

void Circuit::Race() {
	if (track_conditions == Weather::Rain) {
		for (int i = 1; i <= amountCars; i++) {
			float fuel_consumed = Cars[i]->consumtion * ((float)length / 100.0f);
			if (Cars[i]->capacity - fuel_consumed < 0) {
				dnf++;
				std::swap(Cars[i], Cars[amountCars - dnf + 1]);
				times[i] = -1;
			}
			else times[i] = (int)((60.0f / (float)Cars[i]->avg_speed_rain) * (float)length);
		}

		for (int i = 1; i < amountCars - dnf; i++) {
			for (int j = i; j <= amountCars - dnf; j++) {
				if (Cars[i]->avg_speed_rain < Cars[j]->avg_speed_rain) {
					std::swap(Cars[i], Cars[j]);
					std::swap(times[i], times[j]);
				}
			}
		}
	}

	else if (track_conditions == Weather::Sunny) {
		for (int i = 1; i <= amountCars; i++) {
			float fuel_consumed = Cars[i]->consumtion * ((float)length / 100.0f);
			if (Cars[i]->capacity - fuel_consumed < 0) {
				dnf++;
				std::swap(Cars[i], Cars[amountCars - dnf + 1]);
				times[i] = -1;
			}
			else times[i] = (int)((60.0f / (float)Cars[i]->avg_speed_sunny) * (float)length);
		}

		for (int i = 1; i < amountCars - dnf; i++) {
			for (int j = i; j <= amountCars - dnf; j++) {
				if (Cars[i]->avg_speed_sunny < Cars[j]->avg_speed_sunny) {
					std::swap(Cars[i], Cars[j]);
					std::swap(times[i], times[j]);
				}
			}
		}
	}

	else if (track_conditions == Weather::Snow) {
		for (int i = 1; i <= amountCars; i++) {
			float fuel_consumed = Cars[i]->consumtion * ((float)length / 100.0f);
			if (Cars[i]->capacity - fuel_consumed < 0) {
				dnf++;
				std::swap(Cars[i], Cars[amountCars - dnf + 1]);
				times[i] = -1;
			}
			else times[i] = (int)((60.0f / (float)Cars[i]->avg_speed_snow) * (float)length);
		}

		for (int i = 1; i < amountCars - dnf; i++) {
			for (int j = i; j <= amountCars - dnf; j++) {
				if (Cars[i]->avg_speed_snow < Cars[j]->avg_speed_snow) {
					std::swap(Cars[i], Cars[j]);
					std::swap(times[i], times[j]);
				}
			}
		}
	}
	
}

void Circuit::ShowFinalRanks() {
	for (int i = 1; i <= amountCars - dnf; i++) {
		std::cout << "Car Model: " << Cars[i]->getName() << " || Time set in minutes: " << times[i] << '\n';
	}
	std::cout << '\n';
}

void Circuit::ShowWhoDidNotFinish() {
	for (int i = amountCars - dnf + 1; i < amountCars; i++){
		std::cout << "Car Model: " << Cars[i]->getName() << " || Time set in minutes: DNF" << '\n';
	}
}