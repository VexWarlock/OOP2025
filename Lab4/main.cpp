#include "Sort.h"
#include <iostream>

int main()
{
    printf("Random Constructor:\n");
    Sort s1(10, 1, 100);
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();

    printf("\nInitializer List Constructor:\n");
    Sort s2{5, 3, 9, 1, 7};
    s2.Print();
    s2.InsertSort(false);
    s2.Print();

    printf("\nExisting Array Constructor:\n");
    int values[] = {12, 45, 23, 7, 89};
    Sort s3(5, values);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();

    printf("\nString Constructor:\n");
    Sort s4("10,4,100,5,70");
    s4.Print();
    s4.BubbleSort(false);
    s4.Print();

    printf("\nVariadic Constructor:\n");
    Sort s5(6, 30, 10, 20, 50, 40, 60);
    s5.Print();
    s5.InsertSort(true);
    s5.Print();

   printf(s5.GetElementFromIndex(2));
   printf(
    cout << "Total elements in s5: " << s5.GetElementsCount() << endl;

    return 0;
}
