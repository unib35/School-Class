#include <iostream>

using namespace std;

class Matrix{
	int num1, num2, num3, num4;
	public:
		Matrix(int num1 = 0, int num2 = 0, int num3 = 0, int num4 = 0){
			this->num1 = num1;
			this->num2 = num2;
			this->num3 = num3;
			this->num4 = num4;
		}
		void show();
		Matrix operator+(Matrix Mtx);
		bool operator==(Matrix Mtx);
		Matrix& operator+=(Matrix Mtx);
};

Matrix Matrix :: operator+(Matrix Mtx){
	Matrix tmp;
	tmp.num1 = this->num1 + Mtx.num1;
	tmp.num2 = this->num2 + Mtx.num2;
	tmp.num3 = this->num3 + Mtx.num3;
	tmp.num4 = this->num4 + Mtx.num4;
	return tmp;
}

bool Matrix :: operator==(Matrix Mtx){
	if( this->num1 == Mtx.num1 &&
		this->num2 == Mtx.num2 &&
		this->num3 == Mtx.num3 &&
		this->num4 == Mtx.num4 ) return true;
	else return false;
}

Matrix& Matrix :: operator+=(Matrix Mtx){
	this->num1 += Mtx.num1;
	this->num2 += Mtx.num2;
	this->num3 += Mtx.num3;
	this->num4 += Mtx.num4;
	return *this;
}

void Matrix :: show(){
	cout << "Matrix = {" << num1 << " " << num2 << " " << num3 << " " << num4 << " }" << endl;
}


int main(int argc, char** argv) {
	Matrix a(1,2,3,4), b(2,3,4,5), c;
	c = a + b;
	a += b;
	a.show();
	b.show();
	c.show();
	if(a==c) cout << "a and c are the same" << endl;
	
	return 0;
}
