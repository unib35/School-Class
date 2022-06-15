#include <iostream>

using namespace std;

class A{
	int x;
public:
	int getX() { return this->x; }
	void setX(int x) { this->x = x; }
};

class B{
	int y;
	A a;
public:
	B(int num1, int num2){
		this->y = num2;
		a.setX(num1);
	}
	void print() {
		cout << "x = " << a.getX() << " y = " << this->y << endl;
	}
};

int main(){
	B b(10, 20);
	b.print();
	return 0;
}
