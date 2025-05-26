#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>

class IndexOutOfBounds : public std::exception {
public:
    const char* what() const throw() override {
        return "Index out of bounds!";
    }
};

class CapacityExceeded : public std::exception {
public:
    const char* what() const throw() override {
        return "Array capacity exceeded!";
    }
};



template<class T>
class ArrayIterator {
private:
    T** ptr;
public:
    ArrayIterator(T** p = nullptr) : ptr(p) {}

    ArrayIterator& operator++() {
        ++ptr;
        return *this;
    }

    ArrayIterator& operator--() {
        --ptr;
        return *this;
    }

    bool operator!=(const ArrayIterator& other) const {
        return ptr != other.ptr;
    }

    T* GetElement() const {
        return *ptr;
    }
};



template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    ~Array() {
        for (int i = 0; i < Size; ++i)
            delete List[i];
        delete[] List;
    }

    Array(const Array<T>& other) {
        Capacity = other.Capacity;
        Size = other.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i)
            List[i] = new T(*other.List[i]);
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size)
            throw IndexOutOfBounds();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity)
            throw CapacityExceeded();
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size)
            throw IndexOutOfBounds();
        if (Size >= Capacity)
            throw CapacityExceeded();

        for (int i = Size; i > index; --i)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size)
            throw IndexOutOfBounds();
        delete List[index];
        for (int i = index; i < Size - 1; ++i)
            List[i] = List[i + 1];
        --Size;
        return *this;
    }

    int GetSize() const { return Size; }
    int GetCapacity() const { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List + Size); }
};

