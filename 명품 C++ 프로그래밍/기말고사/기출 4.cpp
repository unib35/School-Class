#include <iostream>

using namespace std;

class Adder{
protected:
	int add(int a, int b){ return a+b; }
};

class Subtractor {
protected:
	int minus(int a, int b){ return a-b; }
};

class Calculator : protected Adder, protected Subtractor{
	public:
		int calc(char op, int num1, int num2){
			switch(op){
				case '+':
					return add(num1, num2);
					break;
				case '-':
					return minus(num1, num2);
					break;
			}
		}
};

int main(){
	Calculator hand;
	cout << "2 + 4 = " << hand.calc('+', 2, 4) << endl;
	cout << "2 + 4 = " << hand.calc('-', 2, 4) << endl;
}
