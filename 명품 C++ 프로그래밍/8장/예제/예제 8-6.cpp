#include <iostream>

using namespace std;

class Base{
	int a;
	protected:
		void setA(int a){ this->a = a; }
	public:
		void showA() { cout << a; }
}; 

class Derived : private Base{
	int b; //setA, showA
	protected:
		void setB(int b){ this->b = b; }
	public:
		void showB() { 
			setA(5);
			showA();
			cout << b;
		}
}; 

class GrandDerived : private Derived{
	int c; //setB, showB
	protected:
		void setAB(int x){
			setA(x); //ÄÄÆÄÀÏ ¿À·ù 
			showA(); 
			setB(x);
		}
}; 



