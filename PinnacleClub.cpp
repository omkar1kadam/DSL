#include <iostream>
#include <string>
using namespace std;

struct Student {
    int PRN;
    string name;
    string memberType;   
    Student *next;
};

class PinnacleClub {
private:
    Student *headSYA;   
    Student *headSYB;   

public:
    PinnacleClub() {
        headSYA = NULL;
        headSYB = NULL;
    }

    
    void addNode(int prn, string name, string memT) {
        Student *p = new Student;
        p->PRN = prn;
        p->name = name;
        p->memberType = memT;
        p->next = NULL;


        if (headSYA == NULL) {
            headSYA = p;
            return;
        }

        
        if (memT == "pres") {
            p->next = headSYA;
            headSYA = p;
            return;
        }

       
        if (memT == "sec") {
            Student *curr = headSYA;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = p;
            return;
        }

        
        Student *curr = headSYA;
        Student *back = NULL;

        
        while (curr != NULL && curr->memberType != "sec") {
            back = curr;
            curr = curr->next;
        }

        
        if (back == NULL) {
            
            p->next = headSYA;
            headSYA = p;
        } else {
            back->next = p;
            p->next = curr;
        }
    }
    
    void deleteNode(int prn) {
        Student *curr,*prev;
        
        if (headSYA == NULL){
            cout << "\nList Empty";
        } else {
        	curr = headSYA;
            while(curr != NULL){
                
                if (curr->PRN == prn) {
                    cout << "found: " << curr->PRN;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if (curr == NULL) {
                cout << "PRN not found";
            } else {
                // if the node is first node as well as last node 
                if (headSYA == curr && curr->next  == NULL){
                    headSYA = NULL;
                    delete curr;
                }
                // if the node is first followed by another nodes
                else if (headSYA == curr && curr->next != NULL) {
                    headSYA = curr->next;
                    delete curr;
                }
                // if the node is the last node 
                else if (headSYA != curr && curr->next == NULL) {
                    prev->next = NULL;
                    delete curr;
                }
                // if the node is in middle node
                else {
                    prev->next = curr->next;
                    delete curr;
                }
            }
        }
    }

    
    void displayList() {
        Student *curr = headSYA;
        cout << "\nHeadSYA-->";
        while (curr) {
            cout << "[" << curr->PRN << "|" << curr->name << "|" << curr->memberType << "]-->";
            curr = curr->next;
        }
        cout << "END" << endl;
    }
};

int main() {
    PinnacleClub stud;

    stud.addNode(101112, "secretary", "sec");
    stud.addNode(456, "omkar3", "regular");
    stud.addNode(123, "President", "pres");
    stud.addNode(789, "omkar4", "regular");
    stud.displayList();
    stud.deleteNode(456);
    stud.displayList();

    return 0;
}








