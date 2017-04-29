#include "student.h"
#include <iostream>

student::student(){
    name = "anon";
    korean_score=0,math_score=0, english_score=0;
}

student::student(int x, int y, int z){
    korean_score = x;
    math_score = y;
    english_score = z;
}

student::~student(){
    std::cout << "~destructor call: " << std::endl;
    std::cout << "name value is: " << name << std::endl;
    std::cout << "korean_score value is: " << korean_score << std::endl;
    std::cout << "math_score value is: " << math_score << std::endl;
    std::cout << "english_score value is: " << english_score << std::endl;
    std::cout << "scores does not mean anything... deleting all records..." << std::endl;
}

void student::printall(){
    std::cout << "name value is: " << name << std::endl;
    std::cout << "korean_score value is: " << korean_score << std::endl;
    std::cout << "math_score value is: " << math_score << std::endl;
    std::cout << "english_score value is: " << english_score << std::endl;
}
