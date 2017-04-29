#include "menu_func.h"
#include <iostream>

student* ask_score_to_add(){
    int korean_score=-1;
    int math_score=-1;
    int english_score=-1;
    std::cout << "Korean Score?" << std::endl;
    std::cin >> korean_score;
    std::cout << "Math Score?" << std::endl;
    std::cin >> math_score;
    std::cout << "English Score?" << std::endl;
    std::cin >> english_score;
    std::cout << "Add Korean:" << korean_score << " points" << std::endl;
    std::cout << "Add Math:" << math_score << " points" << std::endl;
    std::cout << "Add English:" << english_score << " points" << std::endl;

    return new student(korean_score, math_score, english_score);
}

void add_student(student **students){
    int i=0;
    for (i = 0; i < MAX_STUDENTS && students[i] != NULL; i++) {
        ;
    }
    std::cout << "i value is: " << i << std::endl;


    if(i >= MAX_STUDENTS){
        std::cout << "No More Enter" << std::endl;
    }else{
        students[i] = ask_score_to_add();
    }
}

void retrieve(student** students){
    int i = 0;
    while(students[i] != NULL){
        std::cout << "# List Number " << i+1 << std::endl;

        students[i]->printall();
        i++;
    }

    std::cout << "Sample n = " << i+1 << std::endl;

}

void getsum(student **students){
    int sum = 0;
}

