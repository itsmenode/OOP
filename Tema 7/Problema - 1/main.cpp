#include <iostream>

namespace temperature_literals {
    constexpr float operator"" _Kelvin(long double k) {
        return static_cast<float>(k - 273.15);
    }

    constexpr float operator"" _Kelvin(unsigned long long int k) {
        return static_cast<float>(k - 273.15);
    }

    constexpr float operator"" _Fahrenheit(long double f) {
        return static_cast<float>((f - 32.0) * 5.0 / 9.0);
    }

    constexpr float operator"" _Fahrenheit(unsigned long long int f) {
        return static_cast<float>((f - 32.0) * 5.0 / 9.0);
    }
}

int main() {
    using namespace temperature_literals;

    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin = " << a << " C" << std::endl;
    std::cout << "120 Fahrenheit = " << b << " C" << std::endl;

    return 0;
}