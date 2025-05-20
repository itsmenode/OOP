#include <iostream>
#include <exception>

// Custom exceptions
class IndexOutOfBoundsException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Indexul este inafara domeniului!";
    }
};

class MemoryAllocationException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Eroare la alocarea memoriei!";
    }
};

class InvalidOperationException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Operatie invalida!";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    T** List;
    int Current;
    int Size;
public:
    ArrayIterator() : List(nullptr), Current(0), Size(0) {}

    ArrayIterator(T** list, int size, int current = 0) : List(list), Size(size), Current(current) {
        if (Current < 0 || (Size > 0 && Current >= Size)) {
            throw IndexOutOfBoundsException();
        }
    }

    ArrayIterator& operator++() {
        if (Current < Size - 1) {
            Current++;
        }
        else {
            throw IndexOutOfBoundsException();
        }
        return *this;
    }

    ArrayIterator& operator--() {
        if (Current > 0) {
            Current--;
        }
        else {
            throw IndexOutOfBoundsException();
        }
        return *this;
    }

    bool operator==(ArrayIterator<T>& other) {
        return List == other.List && Current == other.Current;
    }

    bool operator!=(ArrayIterator<T>& other) {
        return !(*this == other);
    }

    T* GetElement() {
        if (Current < 0 || Current >= Size) {
            throw IndexOutOfBoundsException();
        }
        return List[Current];
    }
};

template<class T>
class Array {
private:
    T** List;      // lista cu pointeri la obiecte de tipul T*
    int Capacity;  // dimensiunea listei de pointeri
    int Size;      // cate elemente sunt in lista

    void Resize(int newCapacity) {
        if (newCapacity <= 0) {
            throw InvalidOperationException();
        }

        T** newList = new (std::nothrow) T * [newCapacity];
        if (newList == nullptr) {
            throw MemoryAllocationException();
        }

        // Copy existing elements
        int copySize = (newCapacity < Size) ? newCapacity : Size;
        for (int i = 0; i < copySize; i++) {
            newList[i] = List[i];
        }

        // Initialize remaining elements to nullptr
        for (int i = copySize; i < newCapacity; i++) {
            newList[i] = nullptr;
        }

        // Delete old list
        delete[] List;

        List = newList;
        Capacity = newCapacity;
        Size = copySize;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}  // Lista nu e alocata, Capacity si Size = 0

    ~Array() {  // destructor
        if (List != nullptr) {
            for (int i = 0; i < Size; i++) {
                delete List[i];
            }
            delete[] List;
        }
    }

    Array(int capacity) {  // Lista e alocata cu 'capacity' elemente
        if (capacity <= 0) {
            throw InvalidOperationException();
        }

        List = new (std::nothrow) T * [capacity];
        if (List == nullptr) {
            throw MemoryAllocationException();
        }

        Capacity = capacity;
        Size = 0;

        for (int i = 0; i < Capacity; i++) {
            List[i] = nullptr;
        }
    }

    Array(const Array<T>& otherArray) {  // constructor de copiere
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;

        if (Capacity > 0) {
            List = new (std::nothrow) T * [Capacity];
            if (List == nullptr) {
                throw MemoryAllocationException();
            }

            for (int i = 0; i < Size; i++) {
                if (otherArray.List[i] != nullptr) {
                    List[i] = new (std::nothrow) T(*(otherArray.List[i]));
                    if (List[i] == nullptr) {
                        // Clean up already allocated memory
                        for (int j = 0; j < i; j++) {
                            delete List[j];
                        }
                        delete[] List;
                        throw MemoryAllocationException();
                    }
                }
                else {
                    List[i] = nullptr;
                }
            }

            for (int i = Size; i < Capacity; i++) {
                List[i] = nullptr;
            }
        }
        else {
            List = nullptr;
        }
    }

    T& operator[](int index) {  // arunca exceptie daca index este out of range
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem) {  // adauga un element de tipul T la sfarsitul listei si returneaza this
        if (Size >= Capacity) {
            // Resize the array if needed
            int newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
            Resize(newCapacity);
        }

        List[Size] = new (std::nothrow) T(newElem);
        if (List[Size] == nullptr) {
            throw MemoryAllocationException();
        }

        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {  // adauga un element pe pozitia index, retureaza this
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }

        if (Size >= Capacity) {
            // Resize the array if needed
            int newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
            Resize(newCapacity);
        }

        // Shift elements to make space for the new element
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }

        List[index] = new (std::nothrow) T(newElem);
        if (List[index] == nullptr) {
            throw MemoryAllocationException();
        }

        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {  // adauga o lista pe pozitia index, retureaza this
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }

        if (otherArray.Size == 0) {
            return *this;  // Nothing to insert
        }

        int newSize = Size + otherArray.Size;
        if (newSize > Capacity) {
            // Ensure we have enough capacity
            Resize(newSize * 2);
        }

        // Shift elements to make space for the new elements
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }

        // Insert other array elements
        for (int i = 0; i < otherArray.Size; i++) {
            if (otherArray.List[i] != nullptr) {
                List[index + i] = new (std::nothrow) T(*(otherArray.List[i]));
                if (List[index + i] == nullptr) {
                    throw MemoryAllocationException();
                }
            }
            else {
                List[index + i] = nullptr;
            }
        }

        Size = newSize;
        return *this;
    }

    const Array<T>& Delete(int index) {  // sterge un element de pe pozitia index, returneaza this
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }

        // Free memory for the element at index
        delete List[index];

        // Shift elements
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }

        List[Size - 1] = nullptr;
        Size--;

        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) {
            return true;  // Self-assignment
        }

        // Clean up existing array
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;

        if (Capacity > 0) {
            List = new (std::nothrow) T * [Capacity];
            if (List == nullptr) {
                throw MemoryAllocationException();
            }

            for (int i = 0; i < Size; i++) {
                if (otherArray.List[i] != nullptr) {
                    List[i] = new (std::nothrow) T(*(otherArray.List[i]));
                    if (List[i] == nullptr) {
                        // Clean up already allocated memory
                        for (int j = 0; j < i; j++) {
                            delete List[j];
                        }
                        delete[] List;
                        throw MemoryAllocationException();
                    }
                }
                else {
                    List[i] = nullptr;
                }
            }

            for (int i = Size; i < Capacity; i++) {
                List[i] = nullptr;
            }
        }
        else {
            List = nullptr;
        }

        return true;
    }

    void Sort() {  // sorteaza folosind comparatia intre elementele din T
        if (Size <= 1) return;

        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*List[i] > *List[j]) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(int (*compare)(const T&, const T&)) {  // sorteaza folosind o functie de comparatie
        if (Size <= 1) return;

        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (compare(*List[i], *List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(Compare* comparator) {  // sorteaza folosind un obiect de comparatie
        if (Size <= 1) return;

        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem) {  // cauta un element folosind binary search in Array
        if (Size == 0) return -1;

        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (*List[mid] == elem) {
                return mid;
            }

            if (*List[mid] < elem) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;  // Element not found
    }

    int BinarySearch(const T& elem, int (*compare)(const T&, const T&)) {  // cauta un element folosind binary search si o functie de comparatie
        if (Size == 0) return -1;

        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int compResult = compare(*List[mid], elem);
            if (compResult == 0) {
                return mid;
            }

            if (compResult < 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;  // Element not found
    }

    int BinarySearch(const T& elem, Compare* comparator) {  // cauta un element folosind binary search si un comparator
        if (Size == 0) return -1;

        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int compResult = comparator->CompareElements(List[mid], (void*)&elem);
            if (compResult == 0) {
                return mid;
            }

            if (compResult < 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;  // Element not found
    }

    int Find(const T& elem) {  // cauta un element in Array
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) {
                return i;
            }
        }
        return -1;  // Element not found
    }

    int Find(const T& elem, int (*compare)(const T&, const T&)) {  // cauta un element folosind o functie de comparatie
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i], elem) == 0) {
                return i;
            }
        }
        return -1;  // Element not found
    }

    int Find(const T& elem, Compare* comparator) {  // cauta un element folosind un comparator
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0) {
                return i;
            }
        }
        return -1;  // Element not found
    }

    int GetSize() {
        return Size;
    }

    int GetCapacity() {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, Size, 0);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size, Size);
    }
};

// Example implementation of a custom comparator
class IntCompare : public Compare {
public:
    virtual int CompareElements(void* e1, void* e2) {
        int* i1 = (int*)e1;
        int* i2 = (int*)e2;
        return *i1 - *i2;
    }
};