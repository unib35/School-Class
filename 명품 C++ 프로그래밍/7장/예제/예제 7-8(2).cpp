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
	b = ++(++a); //���������� �ʿ��Ѱ��
	//a�� �����Ǹ鼭 ������ �ʿ�����Ͱ�����, 2���̻��� �������ߺ��Լ��� ����Ϸ��� ���������� �ʿ��ϴ�. 
	a.show();
	b.show();
}

