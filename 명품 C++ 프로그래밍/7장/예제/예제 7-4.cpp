#include <iostream>

using namespace std;

class Power{
	int kick;
	int punch;
public:
	Power(int kick=0, int punch=0){
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+(Power op);
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power Power :: operator+(Power op){
	Power tmp;
	tmp.kick = this->kick + op.kick;
	tmp.punch = this->punch + op.punch;
	return tmp;
}

int main(){
	Power a(1,2), b(3,5), c;
	a.show();
	b.show();
	c.show();
	c = a + b;
	c.show();
}

