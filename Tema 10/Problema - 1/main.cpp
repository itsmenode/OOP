#include "header.h"
#include <iostream>
using namespace std;

int main() {
    try {
        Array<int> arr(5);

        arr += 10;
        arr += 20;
        arr += 30;

        cout << "Array size: " << arr.GetSize() << endl;

        cout << "Elements: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr.Insert(1, 15);
        cout << "After inserting 15 at position 1: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr.Delete(2);
        cout << "After deleting element at position 2: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Using iterator: ";
        ArrayIterator<int> it = arr.GetBeginIterator();
        ArrayIterator<int> end = arr.GetEndIterator();

        while (it != end) {
            cout << *it.GetElement() << " ";
            ++it;
        }
        cout << endl;

        try {
            cout << "Trying to access element at index 10: " << arr[10] << endl;
        }
        catch (exception& e) {
            cout << "Exception caught: " << e.what() << endl;
        }

        try {
            Array<int> invalidArr(-5);
        }
        catch (exception& e) {
            cout << "Exception caught when creating array with negative capacity: " << e.what() << endl;
        }

        IntCompare intCompare;
        arr.Sort(&intCompare);
        cout << "After sorting with custom comparator: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        Array<int> arrCopy(arr);
        cout << "Copy of array: ";
        for (int i = 0; i < arrCopy.GetSize(); i++) {
            cout << arrCopy[i] << " ";
        }
        cout << endl;

        int index = arr.Find(15);
        if (index != -1) {
            cout << "Found element 15 at index: " << index << endl;
        }
        else {
            cout << "Element 15 not found" << endl;
        }

        index = arr.BinarySearch(15);
        if (index != -1) {
            cout << "Binary search found element 15 at index: " << index << endl;
        }
        else {
            cout << "Binary search: Element 15 not found" << endl;
        }

    }
    catch (exception& e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}