#pragma once

class Student {
private:
    char name[64];
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    Student();

    void setName(const char* newName);
    const char* getName() const;

    void setMathGrade(float grade);
    float getMathGrade() const;

    void setEnglishGrade(float grade);
    float getEnglishGrade() const;

    void setHistoryGrade(float grade);
    float getHistoryGrade() const;

    float getAverage() const;
};
