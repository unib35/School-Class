#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
	int sex;
	string name;
public:
	int getsex() {return this->sex;}
	string getname() {return this->name;}
	Person(string name, int sex) {this->name=name; this->sex=sex;}
	virtual void print() = 0;
};

class Men : public Person{
public:
	Men(string name="", int sex = 1) : Person(name, sex){}
	void print() { cout << "³²ÀÚ : " << getname() << endl; }
};

class Woman : public Person{
public:
	Woman(string name="", int sex = 2) : Person(name, sex){}
	void print() { cout << "¿©ÀÚ : "<< getname() << endl; }
};

int main() {
	
	vector<Person *> p;
	p.push_back(new Men("±æµ¿"));
	p.push_back(new Woman("¿µÈñ"));
	p.push_back(new Men("Ã¶¼ö"));
	p.push_back(new Men("¹Î¼ö"));
	p.push_back(new Woman("¼øÀÚ"));
	
	for(int i = 0;i<p.size();i++){
		if(p[i]->getsex() == 1){
			p[i]->print();
		} 
	}
	for(int i = 0;i<p.size();i++){
		if(p[i]->getsex() == 2){
			p[i]->print();
		} 
	}
}
