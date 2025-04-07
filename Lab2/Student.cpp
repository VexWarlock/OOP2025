#include "Student.h"
#include <cstring>

Student::Student() {
    name[0] = '\0';
    mathGrade = englishGrade = historyGrade = 1.0f;
}

void Student::setName(const char* newName) {
    strncpy(name, newName, sizeof(name));
    name[sizeof(name) - 1] = '\0';
}

const char* Student::getName() const {
    return name;
}

void Student::setMathGrade(float grade) {
    if (grade < 1.0f) grade = 1.0f;
    if (grade > 10.0f) grade = 10.0f;
    mathGrade = grade;
}

float Student::getMathGrade() const {
    return mathGrade;
}

void Student::setEnglishGrade(float grade) {
    if (grade < 1.0f) grade = 1.0f;
    if (grade > 10.0f) grade = 10.0f;
    englishGrade = grade;
}

float Student::getEnglishGrade() const {
    return englishGrade;
}

void Student::setHistoryGrade(float grade) {
    if (grade < 1.0f) grade = 1.0f;
    if (grade > 10.0f) grade = 10.0f;
    historyGrade = grade;
}

float Student::getHistoryGrade() const {
    return historyGrade;
}

float Student::getAverage() const {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}
