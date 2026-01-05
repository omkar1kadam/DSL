#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		Node (int d){
			data = d;
			prev = nullptr;
			next = nullptr;
		}
};
// nullptr
class LinkedList{
	private:
		int size = 10;
		Node* head;
	public:

		LinkedList(){
			head = nullptr;
		}		
		
		void addNode(int d){
			if (head == nullptr){
				cout<< "List is empty"<<endl;
				Node* newNode = new Node(d);
				head = newNode;
			} else {
				Node* curr = head;
				while (curr->next != nullptr){
					curr = curr-> next;
				}
				Node* newNode = new Node(d);
				curr->next = newNode;
				newNode->prev = curr;
			}
			
		}
};

int Main(){
	LinkedList l1;
	l1.addNode(3);
	l1.addNode(4);
	return 0;
}
