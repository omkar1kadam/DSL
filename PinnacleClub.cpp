#include<iostream>
#include<ios>
#include<limits>
#include<algorithm>
using namespace std;

struct Student{
	int PRN;
	string name;
	string memberType;
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
		
		void addNode(int prn,string name,string memT){
			Student *p;
			p = new Student;
			p->PRN=prn;
			p->memberType=memT;
			p->name=name;
			p->next=NULL;
			
			if(headSYA == NULL){
				headSYA = p;
			} else {
			
				if (p->memberType=="regular") {
					Student *curr,*back;
					back = curr = headSYA;
					while(curr->next != NULL){
						back = curr;
						curr=curr->next;
					}
					if (curr->memberType=="sec"){
						back->next=p;
						p->next=curr;
					} else {
						curr->next=p;
					}
					
				}
			}
		}
		
		void displayList(){
			Student *curr;
			curr = headSYA;
			cout<<"\nHeadSYA-->";
			while(curr){
				cout<<"["<<curr->PRN<<"|"<<curr->name<<"|"<<curr->memberType<<"]-->";
				curr=curr->next;
			}
			cout<<"END"<<endl;
		}
};

int main(){
	PinnacleClub stud;
	stud.addNode(123,"omkar","regular");
	
	stud.addNode(789,"omkar3","regular");
	stud.addNode(1011,"omkar4","regular");
	
	stud.displayList();
	return 0;
}
