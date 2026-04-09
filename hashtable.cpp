#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
#define BSIZE 10
using namespace std;

typedef struct Client{
	long int telephone;
	string name;
}CLIENT;

class TelePhoneDirectory{
	private:
		CLIENT LPHT[BSIZE];
		CLIENT QPHT[BSIZE];
		CLIENT cObj;
	public:
		
		void readDataLP();
		void printDataLP();
		void insertDataLP();
		void displayDataLP();
		void searchDataLP(long int);
};

void TelePhoneDirectory::readDataLP(){
	long int telephone;
	string name;
	cout<<"\nEnter Client telephone No: ";
	cin>>cObj.telephone;
	cout<<"\nEnter Client name: ";
	cin>>cObj.name;
};

void TelePhoneDirectory::printDataLP(){
	cout<<"\nClient telephone No: "<<cObj.telephone<<endl;
	cout<<"\nClient name: "<<cObj.name<<endl;
	cin>>cObj.name;
};

void TelePhoneDirectory::insertRecordLP(){
	
};

int main(){
	return 0;
}
