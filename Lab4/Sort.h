#pragma once
#include <initializer_list>

class Sort
{
private:
    int* arr;
    int size;

public:
    // Constructors
    Sort(int numElements, int min, int max);
    Sort(int count, int* values);
    Sort(const char* numbers);
    Sort(std::initializer_list<int> list);
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
