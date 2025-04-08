#include "Math.h"
#include <cstdio>

int main()
{
    printf("Add(2, 3) = %d\n", Math::Add(2, 3));
    printf("Add(2, 3, 4) = %d\n", Math::Add(2, 3, 4));
    printf("Add(2.5, 3.5) = %d\n", Math::Add(2.5, 3.5));
    printf("Add(1.1, 2.2, 3.3) = %d\n", Math::Add(1.1, 2.2, 3.3));

    printf("Mul(3, 4) = %d\n", Math::Mul(3, 4));
    printf("Mul(2, 3, 4) = %d\n", Math::Mul(2, 3, 4));
    printf("Mul(2.5, 4.0) = %d\n", Math::Mul(2.5, 4.0));
    printf("Mul(1.5, 2.0, 3.0) = %d\n", Math::Mul(1.5, 2.0, 3.0));

    printf("Add(5, 1, 2, 3, 4, 5) = %d\n", Math::Add(5, 1, 2, 3, 4, 5));

    char* result = Math::Add("Hello, ", "World!");
    if (result)
    {
        printf("Add(\"Hello, \", \"World!\") = %s\n", result);
        delete[] result;
    }
    else
    {
        printf("String Add returned nullptr\n");
    }

}
