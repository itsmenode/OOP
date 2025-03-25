#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

using namespace std;

Sort::Sort(int count, int min, int max) : size(count) {
    arr = new int[size];
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

Sort::Sort(std::initializer_list<int> list) : size(list.size()) {
    arr = new int[size];
    int i = 0;
    for (int val : list) {
        arr[i++] = val;
    }
}

Sort::Sort(const int* vector, int count) : size(count) {
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = vector[i];
    }
}

Sort::Sort(const char* numbers) {
    size = 1;
    for (const char* ptr = numbers; *ptr; ++ptr) {
        if (*ptr == ',') size++;
    }

    arr = new int[size];
    char* copy = new char[strlen(numbers) + 1];
    strcpy(copy, numbers);

    char* token = strtok(copy, ",");
    int i = 0;
    while (token) {
        arr[i++] = atoi(token);
        token = strtok(nullptr, ",");
    }

    delete[] copy;
}

Sort::Sort(int count, ...) : size(count) {
    arr = new int[size];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < size; i++) {
        arr[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::~Sort() {
    delete[] arr;
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? arr[j] > key : arr[j] < key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ascendent ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sort::QuickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partition(low, high, ascendent);
        QuickSortHelper(low, pi - 1, ascendent);
        QuickSortHelper(pi + 1, high, ascendent);
    }
}

int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (ascendent ? arr[j] < pivot : arr[j] > pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(0, size - 1, ascendent);
}

void Sort::Print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Sort::GetElementsCount() {
    return size;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    return -1;
}
