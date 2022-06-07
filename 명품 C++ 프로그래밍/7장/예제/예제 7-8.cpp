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
	Power operator++();
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power Power :: operator++(){
	this->kick++;
	this->punch++;
	return *this;
}

// ++ 단항연산자 참조가 필요한경우 


int main(){
	Power a(1,1), b;
	//++a; 
	//return * this 나 참조가 없어도 a 값이 변한다. 
	//그 이유는 a 객체의 멤버함수 ++ 은 a의 멤버 변수에 접근이 가능하기 때문. 
	
	b = ++(++a);// 참조가 없으면 a = 2,2 b = 3,3 참조가 있다면 a = 3,3 b = 3,3 
	a.show();
	b.show();
}

