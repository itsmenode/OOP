#include "Math.h"

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c) {
	return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c) {
	return static_cast<int>(a * b * b);
}

int Math::Add(int count, ...) {
	if (count <= 0) return 0;

	va_list args;
	va_start(args, count);
	int sum = 0;

	for (int i = 0; i < count; i++) {
		sum += va_arg(args, int);
	}

	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2) {
	if (!s1 || !s2) return nullptr;

	int lg1 = 0, lg2 = 0;

	while (s1[lg1] != '\0') lg1++;
	while (s2[lg2] != '\0') lg2++;

	char* rez = (char*)malloc(lg1 + lg2 + 1);
	if (!rez) return nullptr;

	for (int i = 0; i < lg1; i++) {
		rez[i] = s1[i];
	}

	for (int i = 0; i < lg2; i++) {
		rez[lg1 + i] = s2[i];
	}

	rez[lg1 + lg2] = '\0';
	return rez;
}