#include <cstdio>
#include <cstring>
#include <cstdlib>

class Number {
private:
    char* value;
    int base;
    int length;

    int CharToDigit(char c) const;
    char DigitToChar(int d) const;
    int ToDecimal() const;
    void FromDecimal(int decimal, int newBase);
    void CopyFrom(const Number& other);
    void MoveFrom(Number&& other);

public:
    Number(const char* value, int base);
    Number(int decimalValue);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(const char* newValue);
    Number& operator=(int decimalValue);

    char operator[](int index) const;
    friend Number operator+(const Number& lhs, const Number& rhs);
    friend Number operator-(const Number& lhs, const Number& rhs);

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

    Number& operator+=(const Number& other);
    Number& operator--();   // Prefix --
    Number operator--(int); // Postfix --
};
