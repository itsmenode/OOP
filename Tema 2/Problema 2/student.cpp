#include "student.h"
#include <iostream>
#include <string>

void student::setName(const std::string& studentName) {
	name = studentName;
}

std::string student::getName() {
	return name;
}

void student::setMathGrade(float x) {
	mathematics = x;
}

float student::getMathGrade() {
	return mathematics;
}

void student::setEnglishGrade(float x) {
	english = x;
}

float student::getEnglishGrade() {
	return english;
}

void student::setHistoryGrade(float x) {
	history = x;
}

float student::getHistoryGrade() {
	return history;
}

float student::averageGrade() {
	return (mathematics + english + history) / 3.0f;
}