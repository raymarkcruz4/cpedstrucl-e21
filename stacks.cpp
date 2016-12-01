#include <iostream>
#include<conio.h>
using namespace std;

class Stack {
  public:
    Stack(int num) {
      top = 0;
      maxelem = num;
      s = new int[maxelem];
    }
    
  void push(int t) {
  
    if (top == maxelem) 
		return;
    s[top++] = t;
  }
  
  int pop() {
  	
    if (top == 0) 
		return -1;
    return s[--top];
  }
  
  void display() {
    if (top == 0) {
      cout << "(empty)\n";
      return;
    }
    for (int t = 0; t < top; t++) 
		cout << s[t] << " ";
    cout << "\n";
  }
  
  int empty() {
    return top == 0;
  }
  
  private:
    int * s;
  int top;
  int maxelem;
};

void menu(){
	Stack * s = new Stack(100);
	int choice,numberPush;
	while(choice!=4){
	cout<<"What would you like to do?:\n";
	cout<<"1: Push:\n";
	cout<<"2: Pop:\n";
	cout<<"3: Display:\n";
	cout<<"4: Exit:\n";
	cout<<"Enter choice:";
	cin>>choice;
	switch (choice)
{
	case 1: 
	cout<<"Input a number to push: ";
	cin>>numberPush;
	s->push(numberPush);
	break;
	
	case 2: 
	s->pop();
	break;
	
	case 3:
	s->display();
	break;
	
	case 4:
	exit(0);
	break;
	
	default:
	cout<<"Wrong input!";

}	
	getch();
	system("cls");
}	
}


int main() {	  
  menu();
  return 1;
}
