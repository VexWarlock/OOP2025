#include <iostream>
#include "NumberList.h"

void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if (count >= 10) return false;
    numbers[count++] = x;
    return true;
}

void NumberList::Sort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                std::swap(numbers[i], numbers[j]);
            }
        }
    }
}

void NumberList::Print() {
    for (int i = 0; i < count; i++) {
        printf("%d ",numbers[i]);
    }
    printf("\n");
}
 
