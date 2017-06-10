#include<iostream>
#include<vector>
using namespace std;

class myclass{
public:
    int hello;
    myclass(){};
    myclass(int b):hello(b){};
};


int add(int a){
    return 0;
}

int main(){

    vector<myclass*> myobjs(10);
    myobjs[1] = new myclass(10);
    int x = add(4);
    std::cout << x << std::endl;

    return 0;
}

