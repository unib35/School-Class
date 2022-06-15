#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vector{
	double x, y;
public:
	Vector(double a = 0, double b = 0){
		this->x = a;
		this->y = b;
	}
	void print(){
		cout << "(" << x << "," << y << ")" << endl;
	}
	friend Vector operator*(Vector op1, double op2);
	friend Vector operator*(double op1, Vector op2);
};

Vector operator*(Vector op1, double op2){
	op1.x *= op2;
	op1.y *= op2;
	return op1;
}

Vector operator*(double op1, Vector op2){
	op2.x *= op1;
	op2.y *= op1;
	return op2;
}

int main(){
	Vector v(1.0, 2.0);
	Vector w=v*2.0;
	Vector z=3.0*v;
	
	w.print();
	z.print();
	return 0;
}
