#pragma once

class Number {
    char* value;
    int base;
    int length;

    void UpdateLength();
    void ConvertFromDecimal(int val, int base);
    int ToDecimal() const;

public:
    Number(const char* value, int base); // Constructor din șir și bază
    Number(int val);                     // Constructor din întreg (baza 10)
    Number(const Number& other);        // Copy constructor
    Number(Number&& other);             // Move constructor
    ~Number();

    Number& operator=(const Number& other);  // Copy assignment
    Number& operator=(Number&& other);       // Move assignment
    Number& operator=(const char* val);      // Assign from const char*
    Number& operator=(int val);              // Assign from int

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();

    char operator[](int index) const;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    friend bool operator>(const Number& a, const Number& b);
    friend bool operator<(const Number& a, const Number& b);
    friend bool operator>=(const Number& a, const Number& b);
    friend bool operator<=(const Number& a, const Number& b);
    friend bool operator==(const Number& a, const Number& b);

    Number& operator+=(const Number& other);

    Number& operator--();   // prefix
    Number operator--(int); // postfix
};
