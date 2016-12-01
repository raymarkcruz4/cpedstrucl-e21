#include <iostream>
using namespace std;

int main(){
	int *ptr;
	int inputn;
	ptr=&inputn;
	cout << "Enter number: ";
	cin >> inputn;
	cout << "The pointer values is " << *ptr << " the memory address is: " << ptr;
	return 0;
}
