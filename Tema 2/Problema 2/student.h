#pragma once

#include <string>

class student {
	std::string name;
	float mathematics;
	float english;
	float history;

public:
	void setName(const std::string& studentName);
	std::string getName();

	void setMathGrade(float x);
	float getMathGrade();

	void setEnglishGrade(float x);
	float getEnglishGrade();

	void setHistoryGrade(float x);
	float getHistoryGrade();

	float averageGrade();
};