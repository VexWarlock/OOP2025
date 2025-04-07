#include "StudentComparison.h"
#include <cstring>

int compareByName(const Student& s1, const Student& s2) {
    int result = strcmp(s1.getName(), s2.getName());
    if (result == 0) return 0;
    return (result > 0) ? 1 : -1;
}

int compareByMath(const Student& s1, const Student& s2) {
    if (s1.getMathGrade() == s2.getMathGrade()) return 0;
    return (s1.getMathGrade() > s2.getMathGrade()) ? 1 : -1;
}

int compareByEnglish(const Student& s1, const Student& s2) {
    if (s1.getEnglishGrade() == s2.getEnglishGrade()) return 0;
    return (s1.getEnglishGrade() > s2.getEnglishGrade()) ? 1 : -1;
}

int compareByHistory(const Student& s1, const Student& s2) {
    if (s1.getHistoryGrade() == s2.getHistoryGrade()) return 0;
    return (s1.getHistoryGrade() > s2.getHistoryGrade()) ? 1 : -1;
}

int compareByAverage(const Student& s1, const Student& s2) {
    float avg1 = s1.getAverage();
    float avg2 = s2.getAverage();
    if (avg1 == avg2) return 0;
    return (avg1 > avg2) ? 1 : -1;
}
