#ifndef MENU_FUNC_H
#define MENU_FUNC_H
#include "student.h"
#include "global.h"
#include <functional>
#include <iostream>
using namespace std;

student* ask_score_to_add();
void add_student(student**);
void retrieve(student**);
void retrieve_analyze(student** );
void fold(student** students, function<int(int,int)> fx, int init);

#endif
