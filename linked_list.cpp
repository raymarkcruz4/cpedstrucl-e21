#include<stdio.h> 
#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;

struct node {
	int data;
	struct node * next;
	struct node * prev;
} *head;
  
int count() {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
    n = n -> next;
    c++;
  }
  return c;
}

void search(int num) {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
  	if(n->data==num){
    cout<<"Location: " << c <<endl;
	} 
    n = n -> next;
    c++;
  }
}


void append(int num) {
  struct node * temp, * right;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  right = (struct node * ) head;
  while (right -> next != NULL)
  right = right -> next;
  right -> next = temp;
  right = temp;
  right -> next = NULL;
}

void add(int num) {
  struct node * temp;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  if (head == NULL) {
    head = temp;
    head -> next = NULL;
  } else {
    temp -> next = head;
    head = temp;
  }
}

void addafter(int num, int loc) {
  int i;
  struct node * temp, * left, * right;
  right = head;
  for (i = 1; i <= loc; i++) {
    left = right;
    right = right -> next; 
  }
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  left -> next = temp;
  left = temp;
  left -> next = right;
  return;
}

int delete_val(int num) {
  struct node * temp, * prev;
  temp = head;
  while (temp != NULL) {
    if (temp -> data == num) {
      if (temp == head) {
        head = temp -> next;
//        free(temp);
        return 1;
      } else {
        prev -> next = temp -> next;
        free(temp);
        return 1;
      }
    } else {
      prev = temp;
      temp = temp -> next;
    }
  }
  return 0;
}

void delete_all(int num) {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
    delete_val(num); 
    n = n -> next;
    c++;
  }
}

void insert(int num) {
  struct node * temp;
  temp = head;
  if (temp == NULL) {
    add(num);
  } else {
    while (temp != NULL) {
      temp = temp -> next;
    }
      append(num);
  }
}


void display(struct node * r) {
  r = head;
  if (r == NULL) {
    return;
  }
  while (r != NULL) {
    printf("%d ", r -> data);
    r = r -> next;
  }
  printf("\n");
}

void reverse(struct node** head_ref) {
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
  int i, num, loc;
  struct node * n;
  head = NULL;
  while (1) {
  	system("cls");
    cout<<"Linked List Operations\n";
    cout<<"===============\n";
    cout<<"1.Insert\n";
    cout<<"2.Add After\n";
    cout<<"3.Display\n";
    cout<<"4.Size\n";
    cout<<"5.Delete\n";
    cout<<"6.Delete Occurance\n";
    cout<<"7.Search\n";
    cout<<"8.Reverse\n";
    cout<<"9.Exit\n";
    cout<<"Enter your choice : ";
    cin>>i;
    if (i <= 0) {
      cout<<"Enter only an Integer\n";
      exit(0);
    } else {
      switch (i) {
      	
      case 1:
        cout<<"\nEnter the number to insert : ";
        cin>>num;
        insert(num);
        break;
        
      case 2:
      	cout<<"\nEnter Value: ";
      	cin>>num;
      	cout<<"Enter Location: ";
      	cin>>loc;
      	addafter(num,loc);
        
      case 3:
        if (head == NULL) {
          cout<<"\nList is Empty\n";
        } else {
          cout<<"Element(s) in the list are : ";
        }
        display(n);
        break;
        
      case 4:
        cout<<"\nSize of the list is " << count() <<endl;
        break;
        
      case 5:
        if (head == NULL)
          cout<<"\nList is Empty\n";
        else {
          cout<<"Enter the number to delete : ";
          cin>> num;
          if (delete_val(num))
            cout<< num <<" deleted successfully\n";
          else
            cout<< num <<" not found in the list\n";
        }
        break;
        
      case 6:
        cout<<"\nEnter number to delete: ";
        cin>>num;
        delete_all(num);
        cout<<"All " << num <<"s has been deleted succesfully";
        break;
        
      case 7:
      	  cout << "\nEnter number to find position: ";
      	  cin >> num;
      	  search(num);
      	  break;
	  	  
	  	  
	  case 8:
        if (head == NULL) {
          cout<<"\nList is Empty\n";
        } else {
          cout<<"Element(s) in the list are : ";
        }
        reverse(&head);
        display(n);
        break;
	  	
      case 9:
        return 0;
		 
      default:
        cout<<"Invalid option\n";
      }
    }
	getch();    
  }
  return 0;
}
