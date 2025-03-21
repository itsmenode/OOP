#include <iostream>
#include "Math.h"

int main() {
    std::cout << Math::Add(2, 3) << std::endl;
    std::cout << Math::Add(2, 3, 4) << std::endl;
    std::cout << Math::Add(2.5, 3.7) << std::endl;
    std::cout << Math::Add(1.2, 2.3, 3.4) << std::endl;

    std::cout << Math::Mul(2, 3) << std::endl;
    std::cout << Math::Mul(2, 3, 4) << std::endl;
    std::cout << Math::Mul(2.5, 3.5) << std::endl;
    std::cout << Math::Mul(1.2, 2.3, 3.4) << std::endl;

    std::cout << Math::Add(5, 1, 2, 3, 4, 5) << std::endl;

    const char* str1 = "De ";
    const char* str2 = "ce?";
    char* result = Math::Add(str1, str2);
    if (result) {
        std::cout << result << std::endl;
        delete[] result;
    }

    return 0;
}
