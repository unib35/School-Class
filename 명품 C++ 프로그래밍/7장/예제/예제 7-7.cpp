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
	Power operator+(int x); 
};


void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

Power Power :: operator+(int x){
	Power tmp;
	tmp.kick = this->kick + x;
	tmp.punch = this->punch + x;
	return tmp;
}

int main(){
	Power a(1,2), b(3,5), c;
	a.show();
	c = a + 2;
	c.show();

}

