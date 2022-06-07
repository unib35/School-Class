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
	friend bool operator == (Power op1, Power op2);
};

void Power :: show(){
	cout << "kick = " << this->	kick << " / punch = " << this->punch << endl;	
}

bool operator == (Power op1, Power op2){
	if(op1.kick == op2.kick && op1.punch == op2.punch) return true;
	else return false;
}

int main(){
	Power a(4,5), b(4,5);
	a.show();
	b.show();
	if(a == b) cout << "equal" << endl;
	else cout << "different" << endl;
}
