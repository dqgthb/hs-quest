#ifndef MENU_FUNC_H
#define MENU_FUNC_H
#include "student.h"
#include "main.h"
#include <functional>
#include <iostream>
using namespace std;

int first_empty_index(student**);
int how_many_students(student**);
void add_student(student**);
student* ask_score();
void retrieve(student**);
void retrieve_analyze(student** );
void print_first_place(student**);
void print_last_place(student**);
void print_mean(student**);
void print_mean_korean(student**);
void print_mean_math(student**);
void print_mean_english(student**);
int calculate_mean_of_subject(student**, int (student::*)());
void print_sum(student**);
void print_sum_korean(student**);
void print_sum_math(student**);
void print_sum_english(student**);
int calculate_sum_of_subject(student**, int (student::*)());
int who_is_the_best_of_this_subject(student**, int (student::*)());
void print_first_place(student**);
int who_is_the_worst_of_this_subject(student**, int (student::*)());
void print_last_place(student**);
void update_student(student **);
void delete_student(student **);
void printall_students(student**);

#endif
