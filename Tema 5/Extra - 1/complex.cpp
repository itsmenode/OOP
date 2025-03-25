#include "complex.h"
#include <cmath>

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag_data == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real_data * real_data + imag_data * imag_data);
}

Complex Complex::conjugate() const {
    return { real_data, -imag_data };
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex operator+(const Complex& l, const Complex& r) {
    return { l.real() + r.real(), l.imag() + r.imag() };
}

Complex operator+(const Complex& l, double r) {
    return { l.real() + r, l.imag() };
}

Complex operator+(double l, const Complex& r) {
    return { l + r.real(), r.imag() };
}

Complex operator-(const Complex& l, const Complex& r) {
    return { l.real() - r.real(), l.imag() - r.imag() };
}

Complex operator-(const Complex& l, double r) {
    return { l.real() - r, l.imag() };
}

Complex operator-(double l, const Complex& r) {
    return { l - r.real(), -r.imag() };
}

Complex operator-(const Complex& obj) {
    return { -obj.real(), -obj.imag() };
}

Complex operator*(const Complex& l, const Complex& r) {
    return { l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real() };
}

Complex operator*(const Complex& l, double r) {
    return { l.real() * r, l.imag() * r };
}

Complex operator*(double l, const Complex& r) {
    return { l * r.real(), l * r.imag() };
}

bool operator==(const Complex& l, const Complex& r) {
    return (l.real() == r.real()) && (l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.real() != 0 || complex.imag() == 0)
        out << complex.real();
    if (complex.imag() != 0) {
        if (complex.imag() > 0 && complex.real() != 0)
            out << " + ";
        else if (complex.imag() < 0)
            out << " - ";
        out << (complex.imag() < 0 ? -complex.imag() : complex.imag()) << "i";
    }
    return out;
}

Complex& Complex::operator++() {
    real_data++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    real_data--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    --(*this);
    return temp;
}