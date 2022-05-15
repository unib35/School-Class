#include <iostream>

using namespace std;

class Power{
	int kick;
	int punch;
public:
	Power(int kick=1, int punch=1){
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power operator+(Power op1, Power op2);
};

void Power :: show(){
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
} 

Power operator+(Power op1, Power op2){
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}

int main(int argc, char** argv) {
	Power a(3,5), b(4,6), c;
	cout << "ÃÊ±â °ª" << endl;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << "c : "; c.show();
	cout << endl;
	
	cout << "c = a + b" << endl;
	c = a + b;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << "c : "; c.show();
	cout << endl;
	
	return 0;
}
