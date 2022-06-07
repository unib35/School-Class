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
	friend Power operator++(Power &op, int x);
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power operator++(Power &op, int x){ //op의 값이 참조로 전달. 
	Power tmp = op; //op의 값이 값에 의한 전달로 tmp에 복사 
	op.kick++; //원본의 op ++ 
	op.punch++;
	return tmp; //증가되기전 op를 담아두었던 tmp를 리턴 
}



int main(){
	Power a(1,1), b;
	b = a++; //a의 증가전 값을 b에 담고, a는 증가됨. 
	a.show(); //2,2 
	b.show(); //1,1
}

