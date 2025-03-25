#include <cstdarg>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Sort {
    int* arr;
    int size;

    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);

public:
    // Constructors
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(const int* vector, int count);
    Sort(const char* numbers);
    Sort(int count, ...);

    // Destructor
    ~Sort();

    // Sorting methods
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    // Utility methods
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};