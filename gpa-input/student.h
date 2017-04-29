#ifndef STUDENT_H
#define STUDENT_H
#include<string>

class student{
 private:
    int korean_score;
    int math_score;
    int english_score;

 public:
    std::string name;
    student();
    student(int,int,int);
    ~student();
    void printall();
};
#endif
