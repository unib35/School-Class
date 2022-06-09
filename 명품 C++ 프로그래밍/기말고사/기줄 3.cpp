#include <iostream>

using namespace std;

class Power{
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0){
		this->kick = kick;
		this->punch = punch;
	}
	
	void show();
	friend Power operator++(Power &op, int x); 
};

void Power :: show(){
	cout << "kick : " << this->kick << " | punch : " << this->punch << endl;
}

Power operator++(Power &op, int x){
	Power tmp = op;
	op.kick++;
	op.punch++;
	return tmp;
}

int main(){
	Power a(3,5), b;
	b = a++;
	a.show();
	b.show();
	return 0;
}
