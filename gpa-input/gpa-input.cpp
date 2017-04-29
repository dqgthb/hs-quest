#include <iostream>
#include <functional>
using namespace std;

class student{
    string name;
    int korean_score;
    int math_score;
    int english_score;

public:
    student(){
        name = "anon";
        korean_score=0,math_score=0, english_score=0;
        return;
    }

    student(int x, int y, int z){
        korean_score = x;
        math_score = y;
        english_score = z;
        return;
    }

    void printall(){
        std::cout << "name value is: " << name << std::endl;

        std::cout << "korean_score value is: " << korean_score << std::endl;
        std::cout << "math_score value is: " << math_score << std::endl;
        std::cout << "english_score value is: " << english_score << std::endl;
    }

    ~student(){
        std::cout << "~destructor call: " << std::endl;

        std::cout << "name value is: " << name << std::endl;

        std::cout << "korean_score value is: " << korean_score << std::endl;
        std::cout << "math_score value is: " << math_score << std::endl;
        std::cout << "english_score value is: " << english_score << std::endl;

        std::cout << "scores does not mean anything... deleting all records..." << std::endl;

    }
};

void stars(int N){
    for (int i=0; i < N; i++) {
        std::cout << "*";
    }
        std::cout << std::endl;
}

    int main(){

        student deon;
        deon.printall();

        student *chris = new student(1,2,3);
        chris->printall();
        delete chris;

        int input=1;
        while(input) {

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
            cin >> input;

            switch (input) {
            case 1: {
                std::cout << "retrieving..." << std::endl;

                break;
            }
            case 2: {
                std::cout << "adding..." << std::endl;
                break;
            }
            case 3: {
                std::cout << "deleting..." << std::endl;
                break;
            }
            case 4: {
                std::cout << "updating..." << std::endl;
                break;
            }
            case 5: {
                std::cout << "quit menu..." << std::endl;
                std::cout << "Bye!" << std::endl;
                input=0;
                break;
            }
            default:
                std::cout << "Please make sure your input is correct." << std::endl;
                break;
            }
        }

        return 0;
    }
