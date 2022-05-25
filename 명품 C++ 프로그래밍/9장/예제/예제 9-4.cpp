#include <iostream>

using namespace std;

class Shape{
	public:
		virtual void draw(){
			cout << "--Shape--(virtual)";
		}
};

class Circle : public Shape {
	public:
		int x;
		virtual void draw() {
			Shape :: draw(); 
			//범위지정을 통해서 강제로 가상으로 지정한 함수를 호출할수 있다. 
			cout << "Circle" << endl;
		}
};

int main(int argc, char** argv) {
	Circle circle;
	Shape * pShape = &circle;
	pShape -> draw(); 
	//부모클래스의 draw로 갔다가 virtual이므로 파생클래스의 draw 생성.
	//파생 draw() 에서 범위지정을 통해서 부모의 draw()를 호출한다. 
	pShape -> Shape::draw(); 
	//범위지정을 통해서 바로 virtual 가상으로 지정된 부모클래스의 draw를 호출가능하다. 
	return 0;
}
