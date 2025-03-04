#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList {
private:
    int numbers[10];
    int count;

public:
    void Init();      // Initializes count to 0
    bool Add(int x);  // Adds x to the list if there is space
    void Sort();      // Sorts the list in ascending order
    void Print();     // Prints the list
};

#endif
 
