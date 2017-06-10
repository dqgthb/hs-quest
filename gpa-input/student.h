#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class student{
 private:
    int korean_score;
    int math_score;
    int english_score;

 public:
    int get_korean_score(){ return korean_score; }
    int get_math_score(){ return math_score; }
    int get_english_score(){ return english_score; }
    std::string name;
    student();
    student(int,int,int);
    ~student();
    void printall();
};
#endif
