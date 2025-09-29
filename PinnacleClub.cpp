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

    stud.addNode(123, "secretary", "sec");
    stud.addNode(789, "omkar3", "regular");
    stud.addNode(456, "President", "pres");
    stud.addNode(1011, "omkar4", "regular");

    stud.displayList();
    return 0;
}
