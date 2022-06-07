#include <iostream>

using namespace std;

class Power{
public:
	int kick;
	int punch;

	Power(int kick=0, int punch=0){
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power operator+(int op1, Power op2);
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power operator+(int op1, Power op2){
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}



int main(){
	Power a(1,1), b;
	b = 2+a;
	a.show();
	b.show();
}

