#ifndef STUDENT_H
#define STUDENT_H
#include<string>

class student{
 private:
    int korean_score;
    int math_score;
    int english_score;

 public:
    int getKor(){ return korean_score; }
    int getMat(){ return math_score; }
    int getEng(){ return english_score; }
    std::string name;
    student();
    student(int,int,int);
    ~student();
    void printall();
};
#endif
