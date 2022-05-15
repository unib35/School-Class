#include <iostream>

using namespace std;

class Color{
	int R, G, B;
public:
	Color(int R=0, int G=0, int B=0){
		this->R = R;
		this->G = G;
		this->B = B;
	}
	void show();
	Color operator+(Color op);
	bool operator==(Color op);
};

Color Color :: operator+(Color op){
	Color tmp;
	tmp.R = this->R + op.R;
	tmp.G = this->G + op.G;
	tmp.B = this->B + op.B;
	return tmp;
}

bool Color :: operator==(Color op){
	if(this->R == op.R && this->G == op.G && this->B == op.B){
		return true;
	} else return false;
}

void Color :: show(){
	cout << R << " " << G << " " << B << endl;
}


int main(int argc, char** argv) {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();
	
	Color fuchsia(255, 0, 255);
	if(c == fuchsia) cout << "보라색 맞음";
	else cout << "보라색 아님";
	return 0;
}
