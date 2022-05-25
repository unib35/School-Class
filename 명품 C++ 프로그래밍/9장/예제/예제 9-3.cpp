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
		//�Ļ�Ŭ������ virtual�� ���������ϴ�. �θ�Ŭ�������� virtual�� ���̸� �ȴ�. 
		//�̸��� ������ �Լ��� �����Ҷ� �����Լ��� �����ϸ� �θ�Ŭ������ �Լ��� ȣ���ص� �Ļ�Ŭ������ ȣ���Ѵ�.  
};

int main(int argc, char** argv) {
	GrandDerived g;
	Base *bp;
	Derived *dp;
	GrandDerived *gp;
	
	//bp = dp = gp = &g; // ��� �����Ͱ� ��ü g�� ����Ų��.
	gp = &g;
	dp = (Derived *)gp;
	bp = (Base *)dp;
	
	bp->f();
	dp->f();
	gp->f();
	return 0;
}
