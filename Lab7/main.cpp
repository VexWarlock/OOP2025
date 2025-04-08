#include <iostream>
using namespace std;

constexpr long double operator"" _Kelvin(long double kelvin) {
    return kelvin - 273.15;
}

constexpr long double operator"" _Fahrenheit(long double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() 
{
    
float a = 300.0_Kelvin;
float b = 120.0_Fahrenheit;
  
cout << "Kelvin to Celsius: " << a << "°C\n";
cout << "Fahrenheit to Celsius: " << b << "°C\n";

}
