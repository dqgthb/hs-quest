#ifndef MENU_FUNC_H
#define MENU_FUNC_H
#include "student.h"
#include "main.h"
#include <functional>
#include <iostream>
using namespace std;

student* ask_score_to_add();
void add_student(student**);
void retrieve(student**);
void retrieve_analyze(student** );
void print_first_place(student**);
void print_last_place(student**);
void print_mean(student**);
void print_mean_korean(student**);
void print_mean_math(student**);
void print_mean_english(student**);
void print_sum(student**);
void print_sum_korean(student**);
void print_sum_math(student**);
void print_sum_english(student**);

#endif
