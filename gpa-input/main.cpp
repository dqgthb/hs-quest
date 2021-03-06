#include <iostream>
#include <functional>
#include "student.h"
#include "menu_func.h"
#include "main.h"

using namespace std;

void loop_program(student **);
int prompt(student **);
void stars(int);

//test
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

typedef struct hello{
    int x;
    int y;
}hello;


int main(){
    int x;
    int y = 5;
    x = y;
    student *chris = new student(50,52,56);
    chris->name = "Chris Moriaty";
    chris->printall();
    student **students = (student **)calloc(MAX_STUDENTS, sizeof *students);
    students[0] = chris;
    students[1] = new student(63,74,45);;
    students[1]->name = "hello";
    loop_program(students);
    std::cout << "loop_program terminated." << std::endl;

    delete chris;
    delete students[1];
    free(students);

    hello *myh = (hello*)malloc(1 * sizeof * myh);

    return 0;
}
