#include <iostream>
#include "Math.h"

int main() {
    std::cout << Math::Add(2, 3) << std::endl;
    std::cout << Math::Add(2, 3, 4) << std::endl;
    std::cout << Math::Add(2.5, 3.5) << std::endl;
    std::cout << Math::Add(2.5, 3.5, 4.5) << std::endl;

    std::cout << Math::Mul(2, 3) << std::endl;
    std::cout << Math::Mul(2, 3, 4) << std::endl;
    std::cout << Math::Mul(2.5, 3.5) << std::endl;
    std::cout << Math::Mul(2.5, 3.5, 4.5) << std::endl;

    std::cout << Math::Add(4, 1, 2, 3, 4) << std::endl;

    char* concatenated = Math::Add("Salutare ", "Viata!");
    if (concatenated) {
        std::cout << concatenated << std::endl;
        free(concatenated);
    }

    return 0;
}