#include <iostream>

float operator"" _Kelvin(long double x) {
	return static_cast<float>(x - 273.15);
}

float operator"" _Kelvin(unsigned long long x) {
	return static_cast<float>(x - 273.15);
}

float operator"" _Fahrenheit(long double x) {
	return static_cast<float>(x - 32) / 1.8;
}

float operator"" _Fahrenheit(unsigned long long x) {
	return static_cast<float>(x - 32) / 1.8;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin = " << a << " C" << std::endl;
    std::cout << "120 Fahrenheit = " << b << " C" << std::endl;

    return 0;
}
