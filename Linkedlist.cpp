#include<iostream>
#include<ios>
#include<limits>
#include<algorithm>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

int main(){
	Node n1,n2,n3;
	
	Node *head;
	head = &n1;
	n1.data=10;
	n1.next=NULL;
	
	
	n2.data=20;
	n2.next=NULL;
	
	n3.data=30;
	n3.next=NULL;
	
	n1.next=&n2;
	n2.next=&n3;
	
	Node *cur;
	cur=head;
	cout<<"\nHead-->";
	while(cur){
	cout<<"["<<cur->data<<"|"<<cur->next<<"]-->";
		cur=cur->next;
	}
	cout<<"END"<<endl;
	
	return 0;
}
