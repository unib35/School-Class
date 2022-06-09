#include <iostream>

using namespace std;

class Math{
	static const int num = 5;
	static double dnum;
public: 
	static int abs(int a) { return a>0?a:-a; }
	static int max(int a, int b) { return (a>b) ? a : b; }
	static int min(int a, int b) { return (a<b) ? a : b; }
	
	
	static int getNum(){
		return num;
	}
	static double getDnum(){
		return dnum;
	}
	
};

//int Math :: num = 15;
double Math :: dnum = 15.0;	

int main(){
	
	Math m;
	cout << Math::abs(-5) << endl;
	cout << Math::max(3,4) << endl;
	cout << Math::min(3,4) << endl; 
	cout << Math::getNum() << endl;
	cout << Math::getDnum() << endl;
	
	cout << m.getDnum() << endl;
}
