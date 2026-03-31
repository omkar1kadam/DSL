#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>	
using namespace std;

typedef struct Employee{
	int EID;
	string name;
	string designation;
	float salary;
}EMP;

class SequentialFile{
	private:
		EMP eObj;
	public:
		void readData();
		void insertRecord();
		void displayData();
		void updateRecord();
		void searchRecord();
		void deleteRecord();
		void displayRecord();
};

void SequentialFile::readData(){
	cout<<"Enter Employee Id: ";
	cin>>eObj.EID;
	cout<<"Enter Employee name: ";
	cin>>eObj.name;
	cout<<"Enter Employee designation: ";
	cin>>eObj.designation;
	cout<<"Enter Employee salary: ";
	cin>>eObj.salary;
}

void SequentialFile::displayData(){
	cout<<" "<<endl;
     cout<<"Employee Id: "<<eObj.EID<<endl;
     cout<<"Employee name: "<<eObj.name<<endl;
     cout<<"Employee designation: "<<eObj.designation<<endl;
     cout<<"Employee salary: "<<eObj.salary<<endl;
        
}

void SequentialFile::insertRecord(){
	fstream fout;
     fout.open("employee.txt",ios::app | ios::binary);
	readData();
	fout.write((char*)&eObj,sizeof(eObj));
	fout.close();
}

void SequentialFile::displayRecord(){
	cout<<"displaying Records: "<<endl;
	fstream fin;
     fin.open("employee.txt",ios::in | ios::binary);
	while(fin.read((char*)&eObj,sizeof(eObj))){
		cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
	}
	fin.close();
}
int main(){
	cout<<"Program starting"<<endl;
	SequentialFile sf;
	//sf.readData();
	//sf.displayData();
	sf.insertRecord();
	sf.displayRecord();
	return 0;

}
