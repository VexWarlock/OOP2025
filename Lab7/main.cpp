#include <cstdio>

constexpr long double operator"" _Kelvin(long double kelvin) {
    return kelvin - 273.15;
}

constexpr long double operator"" _Fahrenheit(long double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() 
{
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    
    printf("Kelvin to Celsius: %.2f°C\n", a);
    printf("Fahrenheit to Celsius: %.2f°C\n", b);

    return 0;
}
