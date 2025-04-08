#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <sstream>

using namespace std;

Sort::Sort(int numElements, int min, int max)
{
    srand(time(nullptr));
    size = numElements;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = min + rand() % (max - min + 1);
}

Sort::Sort(int count, int* values)
{
    size = count;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = values[i];
}

Sort::Sort(const char* numbers)
{
    stringstream ss(numbers);
    string temp;
    size = 0;

    while (getline(ss, temp, ','))
        size++;

    arr = new int[size];
    ss.clear();
    ss.seekg(0);
    ss.str(numbers);

    int i = 0;
    while (getline(ss, temp, ','))
        arr[i++] = stoi(temp);
}

Sort::Sort(initializer_list<int> list)
{
    size = list.size();
    arr = new int[size];
    int i = 0;
    for (int val : list)
        arr[i++] = val;
}

Sort::Sort(int count, ...)
{
    size = count;
    arr = new int[size];

    va_list args;
    va_start(args, count);
    for (int i = 0; i < size; ++i)
        arr[i] = va_arg(args, int);
    va_end(args);
}

Sort::~Sort()
{
    delete[] arr;
}

void Sort::BubbleSort(bool asc)
{
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if ((asc && arr[j] > arr[j + 1]) || (!asc && arr[j] < arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

void Sort::InsertSort(bool asc)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((asc && arr[j] > key) || (!asc && arr[j] < key)))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, bool asc)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if ((asc && arr[j] <= pivot) || (!asc && arr[j] >= pivot))
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRecursive(int arr[], int low, int high, bool asc)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, asc);
        quickSortRecursive(arr, low, pi - 1, asc);
        quickSortRecursive(arr, pi + 1, high, asc);
    }
}

void Sort::QuickSort(bool asc)
{
    quickSortRecursive(arr, 0, size - 1, asc);
}

void Sort::Print()
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int Sort::GetElementsCount()
{
    return size;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < size)
        return arr[index];
    return -1;
}
-
