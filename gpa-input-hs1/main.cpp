#include <iostream>
#include <stdlib.h>

#define MAX_DATA 40
#define NOT_EXIST -1

using namespace std;

struct student_data {
   
   int number;
   bool exist;

   struct score_data {
      int korean, math, english;
   } score;
} student[MAX_DATA];


int is_number_proper(int keyword, int except = -1) {
   for (int i = 0; i < MAX_DATA; i++)
      if (student[i].exist == true &&i != except && student[i].number == keyword)
         return i;
   return NOT_EXIST;
}

void input_data(int data_number) {
   
   cout << "국어 점수를 입력해 주세요 : ";
   while (1) {
      cin >> student[data_number].score.korean;
      if (student[data_number].score.korean > 100 ||
         student[data_number].score.korean < 0) {
         cout << "0부터 100 사이의 숫자를 입력하세요 : ";
         continue;
      }
      break;
   }

   cout << "수학 점수를 입력해 주세요 : ";
   while (1) {
      cin >> student[data_number].score.math;
      if (student[data_number].score.math > 100 ||
         student[data_number].score.math < 0) {
         cout << "0부터 100 사이의 숫자를 입력하세요 : ";
         continue;
      }
      break;
   }

   cout << "영어 점수를 입력해 주세요 : ";
   while (1)
   {
      cin >> student[data_number].score.english;
      if (student[data_number].score.english > 100 ||
         student[data_number].score.english < 0)
      {
         cout << "0부터 100 사이의 숫자를 입력하세요 : ";
         continue;
      }
      break;
   }

   student[data_number].exist = true;
}

void print_data(int data_number) {
   cout <<
      data_number+1 <<
      "\n국어점수 : " << student[data_number].score.korean <<
      "\n수학점수 : " << student[data_number].score.math <<
      "\n영어점수 :" << student[data_number].score.english<<
      "\n평균 : " << (double)(student[data_number].score.korean + student[data_number].score.math + student[data_number].score.english) / 3<<
      "\n";
}

void initialize(void) {
   for (int i = 0; i < MAX_DATA; i++)
      student[i].exist = false;
}

void add_student(void) {
   int i;

   for (i = 0; i < MAX_DATA; i++)
      if (student[i].exist == false)
         break;

   if (i != MAX_DATA) {
      input_data(i);
      cout << "추가하였습니다.\n";
   }
   else
      cout << "학생 수가 최대입니다.\n";
}

void delete_student(void) {
   int keyword, data_number;

   cout << "삭제할 학생의 번호를 입력하세요 : ";
   cin >> data_number;

   if (data_number-1 != NOT_EXIST) {
      student[data_number-1].exist = false;
      cout << "삭제하였습니다.\n";
   }
   else
      cout << "삭제할 학생이 존재하지 않습니다.\n";
}

void modify_student(void) {
   int keyword, data_number;

   cout << "수정할 학생의 번호를 입력하세요 : ";
   cin >> data_number;
   if (data_number-1 != NOT_EXIST) {
      input_data(data_number-1);
      cout << "수정하였습니다.\n";
   }
   else
      cout << "수정할 학생이 존재하지 않습니다.\n";
}


void print_all_student(void) {
   for (int i = 0; i < MAX_DATA; i++)
      if (student[i].exist == true)
         print_data(i);
}


int main(void) {
   char menu_select;

   initialize();
   cout << "= 학생 관리 프로그램입니다 =\n";

   while (1) {
      cout << "\n메뉴를 선택해 주세요\n추가(1) 삭제(2) 수정(3) 검색(4) 출력(5) 종료(6) : ";

      // 입력 버퍼를 비운다
      do {
         menu_select = getchar();
      } while (menu_select == '\n');
      while (getchar() != '\n');

      switch (menu_select) {
      case '1':
         add_student(); break;

      case '2':
         delete_student(); break;

      case '3':
         modify_student(); break;

      case '5':
         print_all_student(); break;

      case '6':
         return 0;

      default:
         cout << "잘못 입력하셨습니다.\n";
      }
   }
}