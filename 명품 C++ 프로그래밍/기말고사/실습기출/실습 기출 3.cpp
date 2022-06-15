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
		cout << "���� : " << getName() << endl;
	}
};

class Women : public Person{
public:
	Women(string name ="", int sex = 2) : Person(name, sex) {}
	void print(){
		cout << "���� : " << getName() << endl;
	}
};

int main(){
	vector<Person *> v;
	v.push_back(new Men("�浿"));
	v.push_back(new Women("����"));
	v.push_back(new Men("ö��"));
	v.push_back(new Men("�μ�"));
	v.push_back(new Women("����"));
	
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
