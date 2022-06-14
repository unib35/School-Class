#include <iostream>

using namespace std;

class A {
	int x;
public :
	A(int x=0){
		this->x = x;
	}
	int getx() {return this->x;}
	void setx(int x) {
		this->x = x;
	} 
};

class B {
	int y;
	A a;
public :
	B(int x, int y){
		a.setx(x);
		this->y = y; 
	}
	void print() {
		cout << "x = " << a.getx() << " y = " << this->y << endl;
	}
};

int main() {
	B b(10, 20);
	b.print();
	return 0;
}
