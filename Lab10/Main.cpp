#include<iostream>

#include "Map.h"
using namespace std;

int main() {
    try {
        Array<int> a(5);
        a += 10;
        a += 20;
        a.Insert(1, 15);

        for (int i = 0; i < a.GetSize(); ++i)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        a.Delete(2);
        a[5] = 42;

    }
    catch (const std::exception& e) {
        std::cerr << "Exceptie: " << e.what() << std::endl;
    }

    return 0;
}
