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

Power operator++(Power &op, int x){ //op�� ���� ������ ����. 
	Power tmp = op; //op�� ���� ���� ���� ���޷� tmp�� ���� 
	op.kick++; //������ op ++ 
	op.punch++;
	return tmp; //�����Ǳ��� op�� ��Ƶξ��� tmp�� ���� 
}



int main(){
	Power a(1,1), b;
	b = a++; //a�� ������ ���� b�� ���, a�� ������. 
	a.show(); //2,2 
	b.show(); //1,1
}

