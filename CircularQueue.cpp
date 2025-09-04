#include<iostream>
#include<limits>
#define MAX 5
using namespace std;
class CircularQueue {
	public:
		int data[MAX];
		int front;
		int rear;
	public:
		CircularQueue(){
			front = -1;
			rear = -1;
		}
		void enqueue(int value){
			if (isFull()){
			    cout << "Queue is Full" << endl;
			}
			else if (isEmpty()){
			    front = rear = 0; 
			    data[rear] = value;
			} else {
			    rear = (rear +1)%MAX;
			    data[rear] = value;
			}
		}
		int dequeue(){
			int val;
			if(!isEmpty()){
				val = data[front];
				if(front == rear) front = rear =-1;
				else front  = (front +1) % MAX;
				return val;
			}
			return -1;
		}
		void display(){
			if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return;
            }
            int i = front;
            while (true) {
                cout << data[i] << " ";
                if (i == rear) break;
                i = (i + 1) % MAX;
                cout << endl;
            }
		}
		bool isEmpty(){
			return rear == -1; 
		}
		bool isFull(){
			return (rear+1)%MAX == front;
		}
	
};
int main(){
	CircularQueue q1;
	cout << "Enter" << endl;
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	
	q1.display();
	
	cout << "" << endl;
	cout << "Out" << endl;
	q1.dequeue();
	q1.dequeue();
	
	q1.display();
	
	cout << "" << endl;
	cout << "ReEnter" << endl;
	q1.enqueue(2);
	q1.enqueue(3);
	
	q1.display();
	
	return 0;
}


