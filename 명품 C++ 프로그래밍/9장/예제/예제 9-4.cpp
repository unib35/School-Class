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
			//���������� ���ؼ� ������ �������� ������ �Լ��� ȣ���Ҽ� �ִ�. 
			cout << "Circle" << endl;
		}
};

int main(int argc, char** argv) {
	Circle circle;
	Shape * pShape = &circle;
	pShape -> draw(); 
	//�θ�Ŭ������ draw�� ���ٰ� virtual�̹Ƿ� �Ļ�Ŭ������ draw ����.
	//�Ļ� draw() ���� ���������� ���ؼ� �θ��� draw()�� ȣ���Ѵ�. 
	pShape -> Shape::draw(); 
	//���������� ���ؼ� �ٷ� virtual �������� ������ �θ�Ŭ������ draw�� ȣ�Ⱑ���ϴ�. 
	return 0;
}
