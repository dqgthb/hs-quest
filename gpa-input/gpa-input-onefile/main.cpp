#include <iostream>
using namespace std;

//originally main.h
///////////////////
#ifndef MAX_STUDENTS
#define MAX_STUDENTS 10
#define MAX_SCORE 100
#define MIN_SCORE 0
#endif

//originally student.h
//////////////////////
#ifndef STUDENT_H
#define STUDENT_H
#include<string>

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

//originally menu_func_h
////////////////////////
#ifndef MENU_FUNC_H
#define MENU_FUNC_H


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

//originally menu_func.cpp
//////////////////////////
// This code returns the index of first empty space.
// e.g. **student = {*student st1, nullptr, *student st2}, then returns 1 (as student[1] is nullptr)
int first_empty_index(student **students){
    int number_of_students= 0;
    for (number_of_students=0; number_of_students<MAX_STUDENTS && students[number_of_students] != nullptr; number_of_students++) {
        ;
    }
    std::cout << "number_of_students value is: " << number_of_students << std::endl;
    return number_of_students;
}

// This returns the total students number in the student**.
int how_many_students(student **students){
    int number_of_students=0;
    for (int i = 0; i < MAX_STUDENTS; i++){
        if (students[i] != nullptr){
            number_of_students++;
        }
    }
    return number_of_students;
}

student* ask_score(){
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
    // requires to get index of first empty space, since we are going to add the new student object there.
    int num = first_empty_index(students);
    if(num >= MAX_STUDENTS){
        std::cout << "No More Enter" << std::endl;
    }else{
        students[num] = ask_score();
    }
}

void printall_students(student** students){
    int i = 0;
    //int num = first_empty_index(students);
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

/*
  int calculate_sum_of_subject(student **students, int (student::*funcp_get_subject_score)(void)){
  int result = 0;
  int num = first_empty_index(students);
  for (int i = 0; i<num; i++){
  result = result + (students[i]->*funcp_get_subject_score)();
  }
  return result;
  }
*/

int calculate_sum_of_subject(student **students, int (student::*funcp_get_subject_score)(void)){
    int result = 0;
    for (int i = 0; i<MAX_STUDENTS; i++){
        if (students[i] != nullptr){
            result = result + (students[i]->*funcp_get_subject_score)();
        }
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
    int num = how_many_students(students);
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

/*
  int who_is_the_best_of_this_subject(student **students, int (student::*funcp)()){
  int num = first_empty_index(students);
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
*/

int who_is_the_best_of_this_subject(student **students, int(student::*funcp)()){
    int max = MIN_SCORE - 1;
    int index_best_student = -1;
    for (int i = 0; i < MAX_STUDENTS; i++){
        if (students[i]!=nullptr){
            int score_of_current_student = (students[i]->*funcp)();
            if(max < score_of_current_student){
                max = score_of_current_student;
                index_best_student = i;
            }
        }
    }
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

/*
int who_is_the_worst_of_this_subject(student **students, int (student::*funcp)()){
    int num = first_empty_index(students);
    int min = 101;
    int index_worst_student = -1;
    for (int i=0; i < num; i++) {
        int score_of_current_student = (students[i]->*funcp)();
        if(min > score_of_current_student){
            min = score_of_current_student;
            index_worst_student = i;
        }
    }
    return index_worst_student;
}
*/

int who_is_the_worst_of_this_subject(student **students, int (student::*funcp)()){
    int min = MAX_SCORE+1;
    int index_worst_student = -1;
    for (int i = 0; i < MAX_STUDENTS; i++){
        if (students[i]!=nullptr){
            int score_of_current_student = (students[i]->*funcp)();
            if(min > score_of_current_student){
                min = score_of_current_student;
                index_worst_student = i;
            }
        }
    }
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
    students[update_no-1] = ask_score();
}

void delete_student(student **students){
    int delete_no = -1;
    std::cout << "Delete No?" << std::endl;
    std::cin >> delete_no;
    delete students[delete_no-1];
    students[delete_no-1]=nullptr;
}

// originally student.cpp
/////////////////////////
student::student(){
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
    std::cout << "<<<<<<<<<<<<<<<<<<<< STUDENT >>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << "name value is: " << name << std::endl;
    std::cout << "korean_score value is: " << korean_score << std::endl;
    std::cout << "math_score value is: " << math_score << std::endl;
    std::cout << "english_score value is: " << english_score << std::endl;
}


// originally main.h
////////////////////
void loop_program(student **);
int prompt(student **);
void stars(int);
void stars(int times){
    for (int i=0; i<times; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void printscreen(){
    stars(30);
    cout << "1. Retrieve\n"
        "2. Add\n"
        "3. Delete\n"
        "4. Update\n"
        "5. Quit"
         << endl;
    stars(30);
    std::cout << ">>> Please enter your input from 1 to 5" << std::endl;
    std::cout << ">";
}

void loop_program(student **students){
    while(1){
        int input;
        input = prompt(students);
        if (input == 5) {
            break;
        }
    }
}

int prompt(student **students){
    int input;
    printscreen();
    std::cin >> input;
    std::cout << "input value is: " << input << std::endl;
    switch (input) {
    case 1: {
        std::cout << "retrieving..." << std::endl;
        retrieve(students);
        break;
    }
    case 2: {
        std::cout << "adding..." << std::endl;
        add_student(students);
        break;
    }
    case 3: {
        std::cout << "deleting..." << std::endl;
        delete_student(students);
        break;
    }
    case 4: {
        std::cout << "updating..." << std::endl;
        update_student(students);
        break;
    }
    case 5: {
        std::cout << "quit menu..." << std::endl;
        std::cout << "Bye!" << std::endl;
        break;
    }
    case 6: {
        std::cout << "hidden! print all students" << std::endl;
        printall_students(students);
        break;
    }
    default:
        std::cout << "No such menu!" << std::endl;
        std::cout << "Please make sure your input is correct." << std::endl;
        break;
    }
    return input;
}

int main(){
    student deon;
    deon.printall();
    student *chris = new student(50,52,56);
    chris->name = "Chris Moriaty";
    chris->printall();
    student **students = (student **)calloc(MAX_STUDENTS, sizeof *students);
    students[0] = chris;
    students[1] = new student(63,74,45);;
    loop_program(students);
    std::cout << "loop_program terminated." << std::endl;

    return 0;
}
