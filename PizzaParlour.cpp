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
		int OIDCount; // generated 
		CircularQueue q;
		int totalQuantity =15;// maximum number of order a customer can order
		int acceptedQuantity = 0;
	public:
		PizzaParlour(){
			OIDCount =0;
		}
		void acceptOrder(int qnt){
			if (acceptedQuantity + qnt > totalQuantity){
			    cout << "Cant process order";
			    char choice;
			    int canTakeOrder = totalQuantity - acceptedQuantity;
			    cout << "We can give you " << canTakeOrder <<"more pizza. do you want it then enter 'y' if no then enter 'n' :" << endl;
			    cin>>choice;
			    if (choice == 'y'){
			        q.enqueue(++OIDCount,canTakeOrder);
			        acceptedQuantity += canTakeOrder;
			    } else {
			        cout << "Thanku" << endl;
			    }
			} else {
			    q.enqueue(++OIDCount,qnt);
			    acceptedQuantity += qnt;
			    cout << acceptedQuantity << endl;
			}
		}
		
		void deliverOrder(){
			q.dequeue();
		}
		
		void checkOrderStatus(){
			q.display();
		}
};
//

int main(){
	PizzaParlour p;
	
	cout << "Enter" << endl;
	p.acceptOrder(2);
	p.acceptOrder(3);
	p.acceptOrder(15);
	p.checkOrderStatus();
	
	cout << "" << endl;
	cout << "Out" << endl;
	p.deliverOrder();
	p.checkOrderStatus();
	
	cout << "" << endl;
	cout << "ReEnter" << endl;
	
	p.acceptOrder(4);
	p.checkOrderStatus();
	
	return 0;
}
