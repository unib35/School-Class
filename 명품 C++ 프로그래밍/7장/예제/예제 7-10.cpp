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
	Power operator++(int x);
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power Power :: operator++(int x){ //���� ++ �����ڴ� ������ �����ؼ��� �ȵȴ�.
	//���������� ���� �����ؾ� �ϱ� ����. 
	Power tmp = *this;
	this->kick++;
	this->punch++;
	return tmp;
}



int main(){
	Power a(1,1), b;
	b = a++; 
	a.show();
	b.show();
}

