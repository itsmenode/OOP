#include "Math.h"
#include <cstdarg>
#include <cstdlib>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return static_cast<int> (a + b);
}

int Math::Add(double a, double b, double c) {
	return static_cast<int> (a + b + c);
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return static_cast<int> (a * b);
}

int Math::Mul(double a, double b, double c) {
	return static_cast<int> (a * b * c);
}

int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}

int stringLength(const char* s) {
	int lg = 0;
	while (s[lg] != '\0') {
		lg++;
	}
	return lg;
}

void stringCopy(char* dest, const char* s) {
	int i = 0;
	while (s[i] != '\0') {
		dest[i] = s[i];;
		i++;
	}
	dest[i] = '\0';
}

void stringConcat(char* dest, const char* s) {
	int i = 0;
	while (dest[i] != '\0') {
		i++;
	}

	int j = 0;
	while (s[j] != '\0') {
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char* Math::Add(const char* s1, const char* s2) {
	if (!s1 || !s2) return nullptr;

	int lg1 = stringLength(s1);
	int lg2 = stringLength(s2);

	char* result = new char[lg1 + lg2 + 1];
	stringCopy(result, s1);
	stringConcat(result, s2);

	return result;
}