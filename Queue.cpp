#include<iostream>
#include<limits>
#define MAX 1000
using namespace std;
class Queue {
	public:
		int data[100];
		int front;
		int rear;
	public:
		Queue(){
			front = -1;
			rear = -1;
		}
		void enqueue(int value){
			if (front == -1) front++;
			if (!isFull()){
				data[++rear] = value;
			}
			else {
				cout << "Queue is Full" << endl;
			}
		}
		int dequeue(){
			int val;
			if(!isEmpty()){
				val = data[front];
				if(front == rear) front = rear =-1;
				else front ++;
				return val;
			}
			return -1;
		}
		void display(){
			for(int i=front; i<=rear; i++){
				cout << data[i] << endl;
			}
		}
		bool isEmpty(){
			return rear == -1; 
		}
		bool isFull(){
			return rear == MAX-1;
		}
	
};
int main(){
	Queue q1;
	cout << "Enter" << endl;
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	
	q1.display();
	
	cout << "Out" << endl;
	q1.dequeue();
	q1.dequeue();
	
	q1.display();
	
	cout << "\nFront : " <<q1.front;
	cout << "\nRear : " << q1.rear << endl;
	return 0;
}



