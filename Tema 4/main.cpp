#include "Sort.h"
#include <iostream>

int main() {
    Sort s1(10, 1, 100);
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();

    Sort s2 = { 10, 40, 100, 5, 70 };
    s2.Print();
    s2.InsertSort(false);
    s2.Print();

    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    Sort s3(arr, 9);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();

    Sort s4("10,40,100,5,70");
    s4.Print();
    s4.BubbleSort(false);
    s4.Print();

    Sort s5(6, 7, 3, 9, 1, 6, 2);
    s5.Print();
    s5.InsertSort(true);
    s5.Print();

    return 0;
}
