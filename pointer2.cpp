#include <iostream>
using namespace std;

main (){
	int *ptr;
	int array[]={1,2,3,4,5};
	ptr=array;
	for (int i=0; i<5; i++){
		cout << *ptr << " ";
		ptr++;
	}
}
