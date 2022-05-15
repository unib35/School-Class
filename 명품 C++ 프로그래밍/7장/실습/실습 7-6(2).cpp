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
		friend Matrix operator+(Matrix Mtx1, Matrix Mtx2);
		friend bool operator==(Matrix Mtx1, Matrix Mtx2);
		friend Matrix& operator+=(Matrix &Mtx1, Matrix Mtx2);
};

Matrix operator+(Matrix Mtx1, Matrix Mtx2){
	Matrix tmp;
	tmp.num1 = Mtx1.num1 + Mtx2.num1;
	tmp.num2 = Mtx1.num2 + Mtx2.num2;
	tmp.num3 = Mtx1.num3 + Mtx2.num3;
	tmp.num4 = Mtx1.num4 + Mtx2.num4;
	return tmp;
}

bool operator==(Matrix Mtx1, Matrix Mtx2){
	if( Mtx1.num1 == Mtx2.num1 &&
		Mtx1.num2 == Mtx2.num2 &&
		Mtx1.num3 == Mtx2.num3 &&
		Mtx1.num4 == Mtx2.num4 ) return true;
	else return false;
}

Matrix& operator+=(Matrix &Mtx1, Matrix Mtx2){
	Mtx1.num1 += Mtx2.num1;
	Mtx1.num2 += Mtx2.num2;
	Mtx1.num3 += Mtx2.num3;
	Mtx1.num4 += Mtx2.num4;
	return Mtx1;
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
