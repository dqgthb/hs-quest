#include <iostream>
using namespace std;

class Calc {
   int n1, n2;
public:
   Calc () {
      n2 = 0;
      n1 = 0;
   }
   void setValue(int x, int y);        // 값을 받아서 a, b 에 각각 저장
   int addition();
   int substition();
   int multiple();
   double division();
};



void Calc::setValue(int x, int y) {
   n1 = x;
   n2 = y;

}

int Calc::addition() {
   return n1 + n2;
}

int Calc::substition() {
   return n1 - n2;
}

int Calc::multiple() {
   return n1 * n2;
}

double Calc::division() {
   return (double)n1 / (double)n2;        // 나눗셈은 결과가 정수가 아닐 수 있으므로 형변환을 시켰다.
}


int main() {
   int x, y;
   char c;
   Calc cal;

   cout << "두 정수와 연산자를 입력하세요 >> ";
   cin >> x >> c >> y;
   cal.setValue(x, y);

   switch (c) {
   case '+':
      cout << cal.addition();
      break;

   case '-':
      cout << cal.substition();
      break;

   case '*':
      cout << cal.multiple();
      break;

   case '/':
      cout << cal.division();
      break;

   default:
      break;
   }
   cout << endl;
}
