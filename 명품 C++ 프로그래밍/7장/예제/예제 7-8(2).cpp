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
	friend Power &operator++(Power &op);
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power & operator++(Power &op){
	op.kick++; 
	op.punch++;
	return op;
}



int main(){
	Power a(1,1), b;
	b = ++(++a); //참조리턴이 필요한경우
	//a가 참조되면서 리턴이 필요없을것같지만, 2개이상의 연산자중복함수를 사용하려면 참조리턴이 필요하다. 
	a.show();
	b.show();
}

