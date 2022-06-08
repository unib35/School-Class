#include <iostream>

using namespace std;

class Circle{
	int radius;
public:
	Circle(int radius=1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class Type>
void myswap(Type &a, Type &b){
	Type tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main(){
	int a = 4, b = 5;
	myswap(a, b);
	cout << "a = " << a << " / " << "b = " << b << endl;
	
	double c = 0.3, d = 1.2;
	myswap(c, d);
	cout << "c = " << c << " / " << "d = " << d << endl;
	
	Circle donut(5), pizza(10);
	myswap(donut, pizza);
	cout << "donut Radius = " << donut.getRadius() << " / " << "pizza Radius = " << pizza.getRadius() << endl;
}
