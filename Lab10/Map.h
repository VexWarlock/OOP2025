#include <iostream>
#include <exception>
using namespace std;


//EXCEPTION CLASSES
class IndexOutOfBoundsException : public exception {
    const char* what() const throw() override {
        return "Index out of bounds!";
    }
};

class CapacityExceededException : public exception {
    const char* what() const throw() override {
        return "Array capacity exceeded!";
    }
};




//COMPARATOR
class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};


//ARRAY ITERATOR
template<class T>
class ArrayIterator {
private:
    T** list;
    int current;
public:
    ArrayIterator(T** l = nullptr, int pos = 0) : list(l), current(pos) {}
    ArrayIterator& operator++() { current++; return *this; }
    ArrayIterator& operator--() { current--; return *this; }
    bool operator!=(const ArrayIterator<T>& other) { return current != other.current; }
    T* GetElement() { return list[current]; }
};


//ARRAY TEMPLATE
template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    Array(const Array<T>& other) : Capacity(other.Capacity), Size(other.Size) {
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) List[i] = new T(*other.List[i]);
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) throw IndexOutOfBoundsException();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) throw CapacityExceededException();
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size || Size >= Capacity) throw IndexOutOfBoundsException();
        for (int i = Size; i > index; i--) List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size || Size + otherArray.Size > Capacity) throw IndexOutOfBoundsException();
        for (int i = Size - 1; i >= index; i--) List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++) List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) throw IndexOutOfBoundsException();
        delete List[index];
        for (int i = index; i < Size - 1; i++) List[i] = List[i + 1];
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) return true;
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) List[i] = new T(*otherArray.List[i]);
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*List[i] > *List[j]) swap(List[i], List[j]);
            }
        }
    }

    void Sort(int(*cmp)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (cmp(*List[i], *List[j]) > 0) swap(List[i], List[j]);
            }
        }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) swap(List[i], List[j]);
            }
        }
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem) return mid;
            if (*List[mid] < elem) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*cmp)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int comp = cmp(*List[mid], elem);
            if (comp == 0) return mid;
            if (comp < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], (void*)&elem);
            if (comp == 0) return mid;
            if (comp < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) if (*List[i] == elem) return i;
        return -1;
    }

    int Find(const T& elem, int(*cmp)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) if (cmp(*List[i], elem) == 0) return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++) if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List, 0); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List, Size); }
};



int main()
{
    try
    {
        Array<int> a(3);
        a+=10;
        a+=20;
        a.Insert(1,15);
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
        a.Delete(1);
        cout << a[0] << " " << a[1] << endl;
        cout << a[10] << endl;
    }
    catch (exception& e) {
        cout<<"Exceptie: "<<e.what()<<endl;
    }
}
