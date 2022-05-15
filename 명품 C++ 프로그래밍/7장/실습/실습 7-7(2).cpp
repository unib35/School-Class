#include <iostream>

using namespace std;

class Matrix{
	int num[4];
	public:
		Matrix(int num1 = 0, int num2 = 0, int num3 = 0, int num4 = 0){
			num[0] = num1;
			num[1] = num2;
			num[2] = num3;
			num[3] = num4;
		}
		void show();
		friend void operator>>(Matrix Mtx, int arr[]);
		friend Matrix& operator<<(Matrix &Mtx, int arr[]);
};

void Matrix :: show(){
	cout << "Matrix = { ";
	for(int i=0;i<4;i++){
		cout << this->num[i] << ' ';
	}
	cout << "}" << endl;
}

void operator>>(Matrix Mtx, int arr[]){
	for(int i=0;i<4;i++){
		arr[i] = Mtx.num[i];
	}
}

Matrix& operator<<(Matrix &Mtx, int arr[]){
	for(int i=0;i<4;i++){
		Mtx.num[i] = arr[i];
	}
	return Mtx;
}

int main(int argc, char** argv) {
	Matrix a(4,3,2,1), b;
	int x[4], y[4] = {1, 2, 3, 4};
	a >> x;
	b << y;
	
	for(int i=0;i<4;i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
	
	return 0;
}
