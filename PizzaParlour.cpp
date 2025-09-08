#include<iostream>
#include<limits>
#define MAX 3
using namespace std;

typedef struct Customer{
	int OID; // order id
	int Quantity; // number of pizza
}CUST;

class CircularQueue {
	public:
		CUST data[MAX];
		int front;
		int rear;
	public:
		CircularQueue(){
			front = -1;
			rear = -1;
		}
		void enqueue(int oid,int quan){
			if (isFull()){
			    cout << "Queue is Full" << endl;
			}
			else if (isEmpty()){
			    front = rear = 0; 
			    data[rear].OID = oid;
			    data[rear].Quantity = quan;
			} else {
			    rear = (rear +1)%MAX;
			    data[rear].OID = oid;
			    data[rear].Quantity = quan;
			}
		}
		int dequeue(){
			int val;
			if(!isEmpty()){
				val = data[front].OID;
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
                cout << "order id: " << data[i].OID <<"   order quantity: " << data[i].Quantity << " ";
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

class PizzaParlour{
	private:
		int M; // maximum number of order a customer can order
		int OIDCount; // generated 
		CircularQueue q;
	public:
		PizzaParlour(){
			OIDCount =0;
		}
		void acceptOrder(int qnt){
			q.enqueue(++OIDCount,qnt);
		}
		
		void deliverOrder(){
			q.dequeue();
		}
		
		void checkOrderStatus(){
			q.display();
		}
};

int main(){
	PizzaParlour p;
	
	cout << "Enter" << endl;
	p.acceptOrder(5);
	p.acceptOrder(6);
	p.acceptOrder(7);
	p.checkOrderStatus();
	
	cout << "" << endl;
	cout << "Out" << endl;
	p.deliverOrder();
	p.checkOrderStatus();
	
	cout << "" << endl;
	cout << "ReEnter" << endl;
	
	p.acceptOrder(8);
	p.checkOrderStatus();
	
	return 0;
}

