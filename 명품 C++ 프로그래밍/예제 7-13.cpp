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
	friend Power& operator++(Power &op); //�ܺ� ���� ���׿������Լ� ������ �Լ� ���� 
	friend Power& operator++(Power &op, int x); //�ܺ� ���� ���׿������Լ� ������ �Լ� ���� 
};

void Power :: show(){
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
} 

Power &operator++(Power &op){ //�ܺο� ����� ���� ���׿����� 
	op.kick++;
	op.punch++;
	return op;
}

Power &operator++(Power &op, int x){ //�ܺο� ����� ���� ���׿����� 
	Power tmp = op; //�������� op tmp�� ���� 
	op.kick++; // ++ 
	op.punch++; // ++
	return tmp; //������ op ����, op�� ������ ������ 
}

int main(int argc, char** argv) {
	Power a(3,5), b;
	cout << "�ʱ� ��" << endl;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << endl;
	
	cout << "���� ���� / b = ++a" << endl;
	b = ++a;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << endl;
	
	cout << "���� ���� / b = a++" << endl;
	b = a++;
	cout << "a : "; a.show();
	cout << "b : "; b.show(); 
	cout << endl;
	
	return 0;
}
