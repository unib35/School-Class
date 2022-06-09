#include <iostream>

using namespace std;

class Rect;


class Rect{
	int width;
	int height;
public:
	Rect(int width, int height){
		this->width = width;
		this->height = height;
	}
	friend bool equal(Rect r, Rect s);
};

bool equal(Rect r, Rect s){
	if(r.width == s.width && s.height == s.height){ return true;	}
	else return false;
}

int main(){
	Rect a(3,4), b(3,4);
	cout << boolalpha << equal(a, b) << endl;
} 
