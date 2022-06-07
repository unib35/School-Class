#include <iostream>

using namespace std;

class Power{
	int kick;
	int punch;
public:
	Power(int kick=0, int punch=0){
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	bool operator == (Power op);
};

void Power :: show(){
	cout << "kick = " << this->kick << " / punch = " << this->punch << endl;
}

bool Power :: operator == (Power op){
	if(this->kick == op.kick && this->punch == op.punch) return true;
	else return false;
}

int main(){
	Power a(3,5), b(3,5);
	a.show();
	b.show();
	
	if(a==b) cout << "두 파워가 같습니다." << endl;
	else cout << "두 파워가 같지 않습니다." << endl;
}
