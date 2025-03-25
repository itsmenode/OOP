#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <utility>

int Number::CharToDigit(char c) const {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

char Number::DigitToChar(int d) const {
    if (d >= 0 && d <= 9) return '0' + d;
    if (d >= 10 && d <= 15) return 'A' + (d - 10);
    return '?';
}

int Number::ToDecimal() const {
    int result = 0;
    for (int i = 0; i < length; ++i) {
        result = result * base + CharToDigit(value[i]);
    }
    return result;
}

void Number::FromDecimal(int decimal, int newBase) {
    char buffer[32];
    int index = 0;
    do {
        buffer[index++] = DigitToChar(decimal % newBase);
        decimal /= newBase;
    } while (decimal > 0);

    delete[] value;
    length = index;
    value = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        value[i] = buffer[length - i - 1];
    }
    value[length] = '\0';
    base = newBase;
}

void Number::CopyFrom(const Number& other) {
    length = other.length;
    base = other.base;
    value = new char[length + 1];
    strcpy(value, other.value);
}

void Number::MoveFrom(Number&& other) {
    value = other.value;
    base = other.base;
    length = other.length;
    other.value = nullptr;
}

Number::Number(const char* value, int base) : base(base) {
    length = strlen(value);
    this->value = new char[length + 1];
    strcpy(this->value, value);
}

Number::Number(int decimalValue) {
    FromDecimal(decimalValue, 10);
}

Number::Number(const Number& other) {
    CopyFrom(other);
}

Number::Number(Number&& other) noexcept {
    MoveFrom(std::move(other));
}

Number::~Number() {
    delete[] value;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        CopyFrom(other);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        MoveFrom(std::move(other));
    }
    return *this;
}

Number& Number::operator=(const char* newValue) {
    delete[] value;
    length = strlen(newValue);
    value = new char[length + 1];
    strcpy(value, newValue);
    return *this;
}

Number& Number::operator=(int decimalValue) {
    FromDecimal(decimalValue, 10);
    return *this;
}

char Number::operator[](int index) const {
    return value[index];
}

Number operator+(const Number& lhs, const Number& rhs) {
    int result = lhs.ToDecimal() + rhs.ToDecimal();
    int maxBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;
    Number sum(0);
    sum.FromDecimal(result, maxBase);
    return sum;
}

Number operator-(const Number& lhs, const Number& rhs) {
    int result = lhs.ToDecimal() - rhs.ToDecimal();
    int maxBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;
    Number diff(0);
    diff.FromDecimal(result, maxBase);
    return diff;
}

bool Number::operator>(const Number& other) const {
    return ToDecimal() > other.ToDecimal();
}

bool Number::operator<(const Number& other) const {
    return ToDecimal() < other.ToDecimal();
}

bool Number::operator>=(const Number& other) const {
    return ToDecimal() >= other.ToDecimal();
}

bool Number::operator<=(const Number& other) const {
    return ToDecimal() <= other.ToDecimal();
}

bool Number::operator==(const Number& other) const {
    return ToDecimal() == other.ToDecimal();
}

bool Number::operator!=(const Number& other) const {
    return ToDecimal() != other.ToDecimal();
}

void Number::SwitchBase(int newBase) {
    int decimal = ToDecimal();
    FromDecimal(decimal, newBase);
}

void Number::Print() const {
    printf("%s (base %d)\n", value, base);
}

int Number::GetDigitsCount() const {
    return length;
}

int Number::GetBase() const {
    return base;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator--() {
    if (length > 1) {
        for (int i = 0; i < length - 1; ++i)
            value[i] = value[i + 1];
        value[--length] = '\0';
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    if (length > 1) {
        value[--length] = '\0';
    }
    return temp;
}