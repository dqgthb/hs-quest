#include <iostream>
using namespace std;

class vendor{

    public:

        void letusstart()
        {
            //while(1){
                cout << "시작메뉴" << endl;
                cout << "---------------------" << endl;
                cout << "1.관리" << endl;
                cout << "2.판매" << endl;
                cout << "3.종료" << endl;
                int startop;
                cin >> startop;
                void startmenu();
                if (startop == 1);
                else if (startop == 2);
                else if (startop == 3)
                    exit(1);
                else
                    cout << "다시 입력하시오";


            //}

        }

        class manage{


            int manuop;

            public:
            manage();
            void manmenu();
            void balance();
            void print();
            void realmanage()
            {
                void startmenu();
                if (manuop == 1)
                    balance();
                else if (manuop == 2)
                    print();
                else if (manuop == 3);
                else
                    cout << "다시 입력하시오";
            }
        };
        class sell{

            private:
                int n1, n2, n3, n4, n5;

            private:

                void sellmenu();
                void selling();
            public:
                sell();

        };
};

vendor::manage::manage(){
}
void vendor::manage::balance()
{
    int need;
    cin >> need;
    int change;
    cin >> change;
    if (need == 1)
        cout << "콜라의 개수는" << change << "입니다.";
    else if (need == 2)
        cout << "사이다의 개수는" << change << "입니다.";
    else if (need == 3)
        cout << "환타의 개수는" << change << "입니다.";
    else if (need == 4)
        cout << "커피의 개수는" << change << "입니다.";
    else if (need == 5)
        cout << "이온음료의 개수는" << change << "입니다.";
    else if (need == 6);
    else
        cout << "올바르게 입력하시오";


}

void vendor::manage::print()
{

    //cout << "콜라는" << n1 << "개 남았습니다.";
    //cout << "사이다는" << n2 << "개 남았습니다.";
    //cout << "환타는" << n3 << "개 남았습니다.";
    //cout << "커피는" << n4 << "개 남았습니다.";
    //cout << "이온음료는" << n5 << "개 남았습니다.";
}

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
    cout << "원하는 음료를 선택하시오";
    cin >> drink;
    if (drink == 1)
        n1 = n1 - 1;
    else if (drink == 1)
        n2 = n2 - 1;
    else if (drink == 1)
        n3 = n3 - 1;
    else if (drink == 1)
        n4 = n4 - 1;
    else if (drink == 1)
        n5 = n5 - 1;
    else if (drink == 6);
    else
        cout << "다시 입력하세요";



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
    int i,j;
    vendor money;
    vendor::manage man;
    vendor::sell se;
    money.letusstart();
    cin >> i;
    if (i == 1)
    {
        man.manmenu();
        cin >> j;
        if (j == 1)
            man.balance();
        else if (j == 2)
            man.print();
        else if (j == 3);
        else
            cout << "다시 쳐줘 제발";
    }
    else if (i == 2)
    {
        ;
    }
    else if (i == 3)
    {
        return 0;
    }


}
