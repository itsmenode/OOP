#include "Canvas.h"
#include <iostream>

int main() {
    Canvas canvas(40, 20);

    canvas.Print();

    std::cout << "\nDrawing a rectangle:\n";
    canvas.DrawRect(5, 5, 20, 15, '#');
    canvas.Print();

    std::cout << "\nFilling a rectangle:\n";
    canvas.FillRect(10, 6, 18, 14, '*');
    canvas.Print();

    std::cout << "\nDrawing a circle:\n";
    canvas.DrawCircle(15, 10, 5, '@');
    canvas.Print();

    std::cout << "\nFilling a circle:\n";
    canvas.FillCircle(30, 10, 3, '+');
    canvas.Print();

    std::cout << "\nDrawing a line:\n";
    canvas.DrawLine(0, 0, 39, 19, '-');
    canvas.Print();

    return 0;
}
