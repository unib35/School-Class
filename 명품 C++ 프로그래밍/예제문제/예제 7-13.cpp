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
	friend Power& operator++(Power &op); //외부 전위 단항연산자함수 프렌드 함수 선언 
	friend Power& operator++(Power &op, int x); //외부 후위 단항연산자함수 프렌드 함수 선언 
};

void Power :: show(){
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
} 

Power &operator++(Power &op){ //외부에 선언된 전위 단항연산자 
	op.kick++;
	op.punch++;
	return op;
}

Power &operator++(Power &op, int x){ //외부에 선언된 후위 단항연산자 
	Power tmp = op; //변경전의 op tmp에 저장 
	op.kick++; // ++ 
	op.punch++; // ++
	return tmp; //변경전 op 리턴, op는 참조로 값변경 
}

int main(int argc, char** argv) {
	Power a(3,5), b;
	cout << "초기 값" << endl;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << endl;
	
	cout << "전위 연산 / b = ++a" << endl;
	b = ++a;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << endl;
	
	cout << "후위 연산 / b = a++" << endl;
	b = a++;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << endl;
	
	return 0;
}
