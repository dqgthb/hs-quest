#include "menu_func.h"
#include <iostream>

int num_of_students(student **students){
    int number_of_students= 0;
    for (number_of_students=0; number_of_students<MAX_STUDENTS && students[number_of_students] != nullptr; number_of_students++) {
        ;
    }
    std::cout << "number_of_students value is: " << number_of_students << std::endl;
    return number_of_students;
}

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
    int num = num_of_students(students);
    if(num >= MAX_STUDENTS){
        std::cout << "No More Enter" << std::endl;
    }else{
        students[num] = ask_score_to_add();
    }
}

void printall_students(student** students){
    int i = 0;
    //int num = num_of_students(students);
    int num = MAX_STUDENTS;
    while(i < num){
        std::cout << "# Student List Number " << i+1 << std::endl;
        if(students[i]!=nullptr){
        students[i]->printall();
        }
        i++;
    }
}

void retrieve(student** students){
    printall_students(students);
    retrieve_analyze(students);
}

void print_sum(student **students){
    print_sum_math(students);
    print_sum_korean(students);
    print_sum_english(students);
}

int calculate_sum_of_subject(student **students, int (student::*funcp_get_subject_score)(void)){
    int result = 0;
    int num = num_of_students(students);
    for (int i = 0; i<num; i++){
        result = result + (students[i]->*funcp_get_subject_score)();
    }
    return result;
}

void print_sum_math(student **students){
    std::cout << "print sum math" << std::endl;
    int sum_math_scores = calculate_sum_of_subject(students, &student::get_math_score);
    std::cout << "sum_math_scores value is: " << sum_math_scores << std::endl;
}

void print_sum_korean(student **students){
    std::cout << "print sum korean" << std::endl;
    int sum_korean_scores = calculate_sum_of_subject(students, &student::get_korean_score);
    std::cout << "sum_korean_scores value is: " << sum_korean_scores << std::endl;
}

void print_sum_english(student **students){
    std::cout << "print sum english" << std::endl;
    int sum_english_scores = calculate_sum_of_subject(students, &student::get_english_score);
    std::cout << "sum_english_scores value is: " << sum_english_scores << std::endl;
}

void print_mean(student **students){
    print_mean_math(students);
    print_mean_korean(students);
    print_mean_english(students);
}

int calculate_mean_of_subject(student **students, int (student::*funcp_get_subject_score)()){
    int sum = calculate_sum_of_subject(students, funcp_get_subject_score);
    int num = num_of_students(students);
    return sum/num;
}

void print_mean_math(student **students){
    std::cout << "print mean math" << std::endl;
    int mean_math = calculate_mean_of_subject(students, &student::get_math_score);
    std::cout << "mean_math value is: " << mean_math << std::endl;
}

void print_mean_korean(student **students){
    std::cout << "print mean korean" << std::endl;
    int mean_korean = calculate_mean_of_subject(students, &student::get_korean_score);
    std::cout << "mean_korean value is: " << mean_korean << std::endl;
}

void print_mean_english(student **students){
    std::cout << "print mean english" << std::endl;
    int mean_english = calculate_mean_of_subject(students, &student::get_english_score);
    std::cout << "mean_english value is: " << mean_english << std::endl;
}


int who_is_the_best_of_this_subject(student **students, int (student::*funcp)()){
    int num = num_of_students(students);
    int max = -1;
    int index_best_student = -1;
    for (int i=0; i < num; i++) {
        int score_of_current_student = (students[i]->*funcp)();
        std::cout << "current max: " << max << std::endl;


        std::cout << "score_of_current_student value is: " << score_of_current_student << std::endl;

        if(max < score_of_current_student){
            max = score_of_current_student;
            index_best_student = i;
        }
    }
    std::cout << "The best score is " << max << std::endl;
    std::cout << "The index of the best student is " << index_best_student << std::endl;
    return index_best_student;
}

void print_first_place(student **students){
    std::cout << ">> print first place" << std::endl;
    std::cout << ">>> print first place math" << std::endl;
    int index_best_math = who_is_the_best_of_this_subject(students, &student::get_math_score);
    students[index_best_math]->printall();
    std::cout << ">>> print first place korean" << std::endl;
    int index_best_korean = who_is_the_best_of_this_subject(students, &student::get_korean_score);
    students[index_best_korean]->printall();
    std::cout << ">>> print first place english" << std::endl;
    int index_best_english = who_is_the_best_of_this_subject(students, &student::get_english_score);
    students[index_best_english]->printall();
}

int who_is_the_worst_of_this_subject(student **students, int (student::*funcp)()){
    int num = num_of_students(students);
    int min = 101;
    int index_worst_student = -1;
    for (int i=0; i < num; i++) {
        int score_of_current_student = (students[i]->*funcp)();
        std::cout << "current min: " << min << std::endl;
        std::cout << "score_of_current_student value is: " << score_of_current_student << std::endl;

        if(min > score_of_current_student){
            min = score_of_current_student;
            index_worst_student = i;
        }
    }
    std::cout << "The worst score is " << min << std::endl;
    std::cout << "The index of the worst student is " << index_worst_student << std::endl;
    return index_worst_student;
}

void print_last_place(student **students){
    std::cout << ">> print last place" << std::endl;
    std::cout << ">>> print last place math" << std::endl;
    int index_worst_math = who_is_the_worst_of_this_subject(students, &student::get_math_score);
    students[index_worst_math]->printall();
    std::cout << ">>> print last place korean" << std::endl;
    int index_worst_korean = who_is_the_worst_of_this_subject(students, &student::get_korean_score);
    students[index_worst_korean]->printall();
    std::cout << ">>> print last place english" << std::endl;
    int index_worst_english = who_is_the_worst_of_this_subject(students, &student::get_english_score);
    students[index_worst_english]->printall();
}

void retrieve_analyze(student **students){
    print_sum(students);
    print_mean(students);
    print_first_place(students);
    print_last_place(students);
}

void update_student(student **students){
    int update_no = -1;
    std::cout << "Update No?" << std::endl;
    std::cin >> update_no;
    students[update_no-1] = ask_score_to_add();
}

void delete_student(student **students){
    int delete_no = -1;
    std::cout << "Delete No?" << std::endl;
    std::cin >> delete_no;
    delete students[delete_no-1];
    students[delete_no-1]=nullptr;
}
