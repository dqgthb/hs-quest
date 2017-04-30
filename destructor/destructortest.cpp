# include<iostream>
using namespace std;

class Circle{
    public:
        int radius;
        Circle();
        Circle(int);
        ~Circle();
        double getArea();
};
Circle::Circle(){
    radius = 1;
    cout << "radius is: "<<radius<<"\n";
}

Circle::Circle(int r){
    radius = r;
    std::cout << "radius is: " << radius << std::endl;
}

Circle::~Circle(){
    std::cout << "destructor call!" << std::endl;
    std::cout << "radius is: " << radius << std::endl;
}

double Circle::getArea(){
    return 3.14 * radius * radius;
}


int main(){
    Circle donut;
    Circle pizza(30);

    Circle *dop = new Circle();
    Circle *pip = new Circle(30);

    delete dop;
    delete pip;

    return 0;
}

