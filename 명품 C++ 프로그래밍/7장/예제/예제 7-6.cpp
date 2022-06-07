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
	friend Power& operator+= (Power &op1, Power op2); 
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power& operator+=(Power &op1, Power op2){
	op1.kick += op2.kick;
	op1.punch += op2.punch;
	return op1;
}

int main(){
	Power a(1,2), b(3,5), c;
	a.show();
	b.show(); 
	(a+=b) += b; //이와 같은 경우를 위해 += 연산자의 리턴을 참조한다. 
	a.show();
	b.show();

}

