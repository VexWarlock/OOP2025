#include "Number.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

Number::Number(const char* val, int base) {
    this->base = base;
    this->length = strlen(val);
    this->value = new char[length + 1];
    strcpy(this->value, val);
}

Number::Number(int val) {
    base = 10;
    ConvertFromDecimal(val, base);
}

Number::~Number() {
    delete[] value;
}

void Number::UpdateLength() {
    length = strlen(value);
}

void Number::ConvertFromDecimal(int val, int base) {
    char buffer[64];
    int i = 0;

    do {
        int digit = val % base;
        buffer[i++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        val /= base;
    } while (val > 0);

    buffer[i] = '\0';

    delete[] value;
    value = new char[i + 1];
    for (int j = 0; j < i; ++j)
        value[j] = buffer[i - j - 1];
    value[i] = '\0';
    UpdateLength();
}

int Number::ToDecimal() const {
    int val = 0;
    for (int i = 0; i < length; ++i) {
        char c = value[i];
        int digit = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
        val = val * base + digit;
    }
    return val;
}

void Number::SwitchBase(int newBase) {
    int val = ToDecimal();
    base = newBase;
    ConvertFromDecimal(val, base);
}

void Number::Print() {
    printf("%s\n", value);
}

int Number::GetDigitsCount() {
    return length;
}

int Number::GetBase() {
    return base;
}

char Number::operator[](int index) const {
    if (index >= 0 && index < length)
        return value[index];
    return '?';
}

// Copy constructor
Number::Number(const Number& other) {
    base = other.base;
    length = other.length;
    value = new char[length + 1];
    strcpy(value, other.value);
}

// Move constructor
Number::Number(Number&& other) {
    base = other.base;
    length = other.length;
    value = other.value;
    other.value = nullptr;
}

// Copy assignment
Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        length = other.length;
        value = new char[length + 1];
        strcpy(value, other.value);
    }
    return *this;
}

// Move assignment
Number& Number::operator=(Number&& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        length = other.length;
        value = other.value;
        other.value = nullptr;
    }
    return *this;
}

// Assign from const char*
Number& Number::operator=(const char* val) {
    delete[] value;
    length = strlen(val);
    value = new char[length + 1];
    strcpy(value, val);
    return *this;
}

// Assign from int
Number& Number::operator=(int val) {
    ConvertFromDecimal(val, base);
    return *this;
}

// Friend addition
Number operator+(const Number& a, const Number& b) {
    int maxBase = (a.base > b.base) ? a.base : b.base;
    int sum = a.ToDecimal() + b.ToDecimal();
    Number result(sum);
    result.SwitchBase(maxBase);
    return result;
}

// Friend subtraction
Number operator-(const Number& a, const Number& b) {
    int maxBase = (a.base > b.base) ? a.base : b.base;
    int diff = a.ToDecimal() - b.ToDecimal();
    Number result(diff);
    result.SwitchBase(maxBase);
    return result;
}

// Relational operators
bool operator>(const Number& a, const Number& b) {
    return a.ToDecimal() > b.ToDecimal();
}

bool operator<(const Number& a, const Number& b) {
    return a.ToDecimal() < b.ToDecimal();
}

bool operator>=(const Number& a, const Number& b) {
    return a.ToDecimal() >= b.ToDecimal();
}

bool operator<=(const Number& a, const Number& b) {
    return a.ToDecimal() <= b.ToDecimal();
}

bool operator==(const Number& a, const Number& b) {
    return a.ToDecimal() == b.ToDecimal();
}

// Compound addition
Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

// Prefix --
Number& Number::operator--() {
    if (length <= 1) return *this;
    for (int i = 1; i < length; ++i)
        value[i - 1] = value[i];
    value[--length] = '\0';
    return *this;
}

// Postfix --
Number Number::operator--(int) {
    Number copy = *this;
    if (length <= 1) return copy;
    value[--length] = '\0';
    return copy;
}
