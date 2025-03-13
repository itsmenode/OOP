#include "Student.h"
#include "globalFunctions.h"
#include <iostream>

int main() {
    student student1, student2;

    student1.setName("Andrei");
    student1.setMathGrade(9);
    student1.setEnglishGrade(8);
    student1.setHistoryGrade(7);

    student2.setName("Mihnea");
    student2.setMathGrade(7);
    student2.setEnglishGrade(9);
    student2.setHistoryGrade(8);

    std::cout << "Comparing by name: " << compareByName(student1, student2) << std::endl;
    std::cout << "Comparing by math grade: " << compareByMath(student1, student2) << std::endl;
    std::cout << "Comparing by English grade: " << compareByEnglish(student1, student2) << std::endl;
    std::cout << "Comparing by history grade: " << compareByHistory(student1, student2) << std::endl;
    std::cout << "Comparing by average grade: " << compareByAverage(student1, student2) << std::endl;

    return 0;
}