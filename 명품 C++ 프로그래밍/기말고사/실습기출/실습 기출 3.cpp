#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
	int sex;
	string name;
public:
	int getSex() { return this->sex;}
	string getName() { return this->name;}
	Person(string name, int sex){
		this->name = name;
		this->sex = sex;
	}
	virtual void print() = 0;
};

class Men : public Person{
public:
	Men(string name ="", int sex = 1) : Person(name, sex) {}
	void print(){
		cout << "³²ÀÚ : " << getName() << endl;
	}
};

class Women : public Person{
public:
	Women(string name ="", int sex = 2) : Person(name, sex) {}
	void print(){
		cout << "¿©ÀÚ : " << getName() << endl;
	}
};

int main(){
	vector<Person *> v;
	v.push_back(new Men("±æµ¿"));
	v.push_back(new Women("¿µÈñ"));
	v.push_back(new Men("Ã¶¼ö"));
	v.push_back(new Men("¹Î¼ö"));
	v.push_back(new Women("¼øÀÚ"));
	
	for(int i =0;i<5;i++){
		if(v[i]->getSex() == 1){
			v[i]->print();
		}
	}
	
	for(int i=0;i<5;i++){
		if(v[i]->getSex() == 2){
			v[i]->print();
		}
	}
	return 0;
} 
