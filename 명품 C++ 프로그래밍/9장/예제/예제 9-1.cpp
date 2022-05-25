#include <iostream>

using namespace std;

class Base{
	public:
		virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base{
	public:
		void f() { cout << "Derived::f() called" << endl; } 
		//�Ļ�Ŭ������ virtual�� ���������ϴ�. �θ�Ŭ�������� virtual�� ���̸� �ȴ�. 
		//�̸��� ������ �Լ��� �����Ҷ� �����Լ��� �����ϸ� �θ�Ŭ������ �Լ��� ȣ���ص� �Ļ�Ŭ������ ȣ���Ѵ�.  
};


int main(int argc, char** argv) {
	Derived d, *pDer;
	pDer = &d;
	pDer -> f();
	Base *pBase;
	pBase = (Base *)pDer; //��ĳ���� 
	pBase -> f();
	return 0;
}
