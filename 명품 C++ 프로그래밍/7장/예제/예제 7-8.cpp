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

// ++ ���׿����� ������ �ʿ��Ѱ�� 


int main(){
	Power a(1,1), b;
	//++a; 
	//return * this �� ������ ��� a ���� ���Ѵ�. 
	//�� ������ a ��ü�� ����Լ� ++ �� a�� ��� ������ ������ �����ϱ� ����. 
	
	b = ++(++a);// ������ ������ a = 2,2 b = 3,3 ������ �ִٸ� a = 3,3 b = 3,3 
	a.show();
	b.show();
}

