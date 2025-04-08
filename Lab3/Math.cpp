#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cstdlib>



int Math::Add(int a, int b) { return a + b; }
int Math::Add(int a, int b, int c) { return a + b + c; }

int Math::Add(double a, double b) { return (int)(a + b); }
int Math::Add(double a, double b, double c) { return (int)(a + b + c); }

int Math::Mul(int a, int b) { return a * b; }
int Math::Mul(int a, int b, int c) { return a * b * c; }

int Math::Mul(double a, double b) { return (int)(a * b); }
int Math::Mul(double a, double b, double c) { return (int)(a * b * c); }



int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; ++i)
        sum += va_arg(args, int);
    va_end(args);
    return sum;
}



char* Math::Add(const char* a, const char* b)
{
    if (!a || !b) return nullptr;

    int len1 = strlen(a);
    int len2 = strlen(b);
    char* result = new char[len1 + len2 + 1];

    strcpy(result, a);
    strcat(result, b);

    return result;
}
