#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <utility>

template<typename K, typename V>
class Map {
private:
    struct Pair {
        K key;
        V value;
    };

    Pair* data;
    size_t capacity;
    size_t size;

    void Resize() {
        size_t newCapacity = capacity * 2;
        Pair* newData = new Pair[newCapacity];
        for (size_t i = 0; i < size; ++i)
            newData[i] = std::move(data[i]);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Map() : capacity(4), size(0) {
        data = new Pair[capacity];
    }

    ~Map() {
        delete[] data;
    }

    V& operator[](const K& key) {
        for (size_t i = 0; i < size; ++i)
            if (data[i].key == key)
                return data[i].value;

        if (size == capacity)
            Resize();

        data[size].key = key;
        data[size].value = V{};
        ++size;
        return data[size - 1].value;
    }

    void Set(const K& key, const V& value) {
        for (size_t i = 0; i < size; ++i) {
            if (data[i].key == key) {
                data[i].value = value;
                return;
            }
        }
        if (size == capacity)
            Resize();
        data[size++] = { key, value };
    }

    bool Get(const K& key, V& value) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i].key == key) {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }

    size_t Count() const {
        return size;
    }

    void Clear() {
        size = 0;
    }

    bool Delete(const K& key) {
        for (size_t i = 0; i < size; ++i) {
            if (data[i].key == key) {
                for (size_t j = i; j < size - 1; ++j)
                    data[j] = std::move(data[j + 1]);
                --size;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        for (size_t i = 0; i < other.size; ++i) {
            bool found = false;
            for (size_t j = 0; j < size; ++j) {
                if (data[j].key == other.data[i].key)
                    found = true;
            }
            if (!found) return false;
        }
        return true;
    }







    struct Iterator {
        Pair* ptr;
        size_t index;

        Iterator(Pair* p, size_t idx) : ptr(p), index(idx) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            ++index;
            ++ptr;
        }

        auto operator*() const {
            return std::tuple<K, V, size_t>(ptr->key, ptr->value, index);
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data + size, size);
    }
};
