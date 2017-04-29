#include <iostream>
using namespace std;

class vendor{

    public:
        void letusstart()
        {
            manage man;
            sell se;
            while(1){
                cout << "시작메뉴" << endl;
                cout << "---------------------" << endl;
                cout << "1.관리" << endl;
                cout << "2.판매" << endl;
                cout << "3.종료" << endl;
                int startop;
                cin >> startop;
                //void startmenu();
                if (startop == 1){
                    man.manmenu();
                    man.realmanage(&se);
                }
                else if (startop == 2){
                    se.sellmenu();
                    se.selling();
                }
                else if (startop == 3)
                    break;
                else
                    cout << "다시 입력하시오"<<endl;
                cin.clear();
            }
            return;
        }
        class sell{

            private:
                int n1, n2, n3, n4, n5;

            public:
                sell();
                void sellmenu();
                void selling();
                void printall();
                void change_n1(int);
                void change_n2(int);
                void change_n3(int);
                void change_n4(int);
                void change_n5(int);

        };

        class manage{


            int manuop;

            public:
            manage();
            void manmenu();
            void balance(vendor::sell *s);
            //void printall(vendor *v);
            void realmanage(vendor::sell *s)
            {
                void startmenu();
                cin >> manuop;
                if (manuop == 1)
                    balance(s);
                else if (manuop == 2)
                    s->printall();
                else if (manuop == 3)
                    return;
                else
                    cout << "다시 입력하시오" << endl;
            }
        };
};
/*void vendor::manage::printall(vendor *v){
  v->mysell.printall();
  }*/
void vendor::sell::printall(){
    std::cout <<"n1: "<< n1 << std::endl;
    std::cout <<"n2: "<< n2 << std::endl;
    std::cout <<"n3: "<< n3 << std::endl;
    std::cout <<"n4: "<< n4 << std::endl;
    std::cout <<"n5: "<< n5 << std::endl;
}

void vendor::sell::change_n1(int n){
    n1 += n;
}
void vendor::sell::change_n2(int n){
    n2 += n;

}
void vendor::sell::change_n3(int n){
    n3 += n;

}
void vendor::sell::change_n4(int n){
    n4 += n;

}
void vendor::sell::change_n5(int n){
    n5 += n;

}

vendor::manage::manage(){
    manuop = 0;
}

void vendor::manage::balance(vendor::sell *s)
{
    std::cout << "현재 재고는 다음과 같습니다." << std::endl;
    s->printall();
    std::cout << "무슨 항목을 바꾸시겠습니까? 1-5 숫자 입력, 종료시 6:" << std::endl;

    int need;
    cin >> need;
    if (need == 6){
        std::cout << "시작메뉴로..." << std::endl;
        return;
    }
    cout << need<< "번 항목을 고르셨습니다."  << endl;
    cout <<  "얼마나 추가하시겠습니까? (제거시 음의 정수 입력)"  << endl;
    int change;
    cin >> change;
    cout << "change is " << change << endl;
    if (need == 1)
        s->change_n1(change);
    else if (need == 2)
        s->change_n2(change);
    else if (need == 3)
        s->change_n3(change);
    else if (need == 4)
        s->change_n4(change);
    else if (need == 5)
        s->change_n5(change);
    else{
        cout << "올바르게 입력하시오" << endl;
    }

    std::cout << "변경 후 재고는 다음과 같습니다." << std::endl; 
    s->printall();
    std::cout << "시작 메뉴로..." << std::endl;


}

//void vendor::manage::print()
//{

//cout << "콜라는" << n1 << "개 남았습니다.";
//cout << "사이다는" << n2 << "개 남았습니다.";
//cout << "환타는" << n3 << "개 남았습니다.";
//cout << "커피는" << n4 << "개 남았습니다.";
//cout << "이온음료는" << n5 << "개 남았습니다.";
//}

vendor::sell::sell(){
    n1=10;
    n2=20;
    n3=30;
    n4=40;
    n5=50;

    //constructor

}
void vendor::sell::selling()
{
    int drink;
    cout << "원하는 음료를 선택하시오" << endl;
    cin >> drink;
    if (drink == 1){
        n1 = n1 - 1;
        std::cout << "남은 갯수" << n1 << std::endl;}
    else if (drink == 2){
        n2 = n2 - 1;
        std::cout << "남은 갯수" << n2 << std::endl;}
    else if (drink == 3){
        n3 = n3 - 1;
        std::cout << "남은 갯수" << n3 << std::endl;}
    else if (drink == 4){
        n4 = n4 - 1;
        std::cout << "남은 갯수" << n4 << std::endl;}
    else if (drink == 5){
        n5 = n5 - 1;
        std::cout << "남은 갯수" << n5 << std::endl;}
    else if (drink == 6)
        return;
    else
        cout << "다시 입력하세요" << endl;



}




void vendor::manage::manmenu()
{
    cout << "관리메뉴" << endl;
    cout << "---------------------" << endl;
    cout << "1.입고/출고" << endl;
    cout << "2.현황 출력" << endl;
    cout << "3.시작메뉴" << endl;
}

void vendor::sell::sellmenu()
{
    cout << "판매메뉴" << endl;
    cout << "---------------------" << endl;
    cout << "1.콜라" << endl;
    cout << "2.사이다" << endl;
    cout << "3.환타" << endl;
    cout << "4.커피" << endl;
    cout << "5.이온음료" << endl;
    cout << "6.시작메뉴" << endl;
}




int main()
{
    vendor money;
    money.letusstart();

}
