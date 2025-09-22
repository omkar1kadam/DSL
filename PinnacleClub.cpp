#include<iostream>
#include<ios>
#include<limits>
#include<algorithm>
using namespace std;

struct Student{
	int PRN;
	string name;
	struct Student *next;
};

class PinnacleClub{
	private:
		Student *headSYA;
		Student *headSYB;
	public:
		PinnacleClub(){
			headSYA = NULL;
			headSYB = NULL;
		}
		
		void addNode(int prn,string name){
			Student *p;
			p = new Student;
			p->PRN=prn;
			p->name=name;
			
			if(headSYA == NULL){
				headSYA = p;
			} else {
				Student *curr;
				curr = headSYA;
				while(curr->next != NULL){
					curr=curr->next;
				}
				curr->next=p;
			}
		}
		
		void displayList(){
			Student *curr;
			curr = headSYA;
			cout<<"\nHeadSYA-->";
			while(curr){
				cout<<"["<<curr->PRN<<"|"<<curr->name<<"]-->";
				curr=curr->next;
			}
			cout<<"END"<<endl;
		}
};

int main(){
	PinnacleClub stud;
	stud.addNode(123,"omkar");
	stud.addNode(456,"omkar2");
	stud.displayList();
	return 0;
}
