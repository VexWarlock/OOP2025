#include <cstdio>
#include "Student.h"
#include "StudentComparison.h"

int main() 
{
    Student s1, s2;

    s1.setName("Marcel");
    s1.setMathGrade(9.5f);
    s1.setEnglishGrade(8.0f);
    s1.setHistoryGrade(7.5f);

    s2.setName("Viorel");
    s2.setMathGrade(8.0f);
    s2.setEnglishGrade(9.0f);
    s2.setHistoryGrade(8.5f);

    printf("Comparare nume: %d\n", compareByName(s1, s2));
    printf("Comparare matematica: %d\n", compareByMath(s1, s2));
    printf("Comparare engleza: %d\n", compareByEnglish(s1, s2));
    printf("Comparare istorie: %d\n", compareByHistory(s1, s2));
    printf("Comparare medie: %d\n", compareByAverage(s1, s2));

}
