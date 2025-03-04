#include <iostream>
#include "NumberList.h"

int main() {
    NumberList list;
    list.Init();

    list.Add(5);
    list.Add(2);
    list.Add(8);
    list.Add(1);
    list.Add(7);

    std::cout << "Unsorted list: ";
    list.Print();

    list.Sort();

    std::cout << "Sorted list: ";
    list.Print();

    return 0;
} 
