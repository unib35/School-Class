#include <iostream>

using namespace std;

void mcopy(Type1 src[], Type2 dest[], int n)																					{
template <class Type1, class Type2> //�ΰ��� �ڷ��� ���ø�!! 
	for(int i=0;i<n;i++)																										{
		dest[i] = (Type2)src[i]		//�̰��� ���̽��ΰ� C++ �ΰ�?																										;																								}}

int main(){
	int x[] = {1,2,3,4,5};
	double d[5];
	char c[5] = {'H', 'e', 'l', 'l', 'o'}, e[5];
	
	mcopy(x, d, 5);
	mcopy(c, e, 5);
	
	for(int i=0;i<5;i++){
		cout << d[i] << ' ';
	}
	cout << endl;
	for(int i=0;i<5;i++){
		cout << e[i] << ' ';
	}
	cout << endl;
}
