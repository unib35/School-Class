#include <iostream>
#include <string> 


using namespace std;


class Student;

class Professor{
	string name;
public:
	Professor(string name) { this->name = name;	}
	friend void show(Student s, Professor p);
};

class Student{
	int id;
public:
	Student(int id) { this->id = id; }
	friend void show(Student s, Professor p);
};




void show(Student s, Professor p) {
	cout << s.id << '.' << p.name;
};

 

int main(){
	Student s(1);
	Professor p("ȫ�浿");
	show(s, p);
	return 0;
}
