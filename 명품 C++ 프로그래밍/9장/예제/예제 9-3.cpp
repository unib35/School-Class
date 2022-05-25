#include <iostream>

using namespace std;

class Base{
	public:
		virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base{
	public:
		void f() { cout << "Derived::f() called" << endl; } 
};

class GrandDerived : public Derived{
	public:
		void f() { cout << "GrandDerived::f() called" << endl; } 
		//파생클래스의 virtual은 생략가능하다. 부모클래스에만 virtual을 붙이면 된다. 
		//이름이 동일한 함수가 존재할때 가상함수로 생성하면 부모클래스의 함수를 호출해도 파생클래스를 호출한다.  
};

int main(int argc, char** argv) {
	GrandDerived g;
	Base *bp;
	Derived *dp;
	GrandDerived *gp;
	
	//bp = dp = gp = &g; // 모든 포인터가 객체 g를 가르킨다.
	gp = &g;
	dp = (Derived *)gp;
	bp = (Base *)dp;
	
	bp->f();
	dp->f();
	gp->f();
	return 0;
}
