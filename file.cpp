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
		void updateRecord_NOT_USING(string oldname,string newname);
		void updateRecord(string name);
		void searchRecord(string);
		void deleteRecord(string);
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

void SequentialFile::searchRecord(string name){
	fstream fin;
     	fin.open("employee.txt",ios::in | ios::binary);
	while(fin.read((char*)&eObj,sizeof(eObj))){
		if(eObj.name == name){
			cout<<"\nRecord Found"<<endl;
			cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
			return;
		}
	}
	fin.close();
        
}

void SequentialFile::updateRecord_NOT_USING(string oldname,string newname){
	fstream finout;
     	finout.open("employee.txt",ios::in | ios::out | ios::binary);
	while(finout.read((char*)&eObj,sizeof(eObj))){
		if(eObj.name == oldname){
			cout<<"\ndoing update"<<endl;
			eObj.name = newname;
			cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
			return;
		}
	}
	finout.close();
}

void SequentialFile::updateRecord(string name){
	fstream finout;
     	finout.open("employee.txt",ios::in | ios::out | ios::binary);
	while(finout.read((char*)&eObj,sizeof(eObj))){
		if(eObj.name == name){
			cout<<"\ndoing update"<<endl;
			cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
			readData();
			finout.seekp(-(sizeof(eObj)),ios::cur);
			finout.write((char*)&eObj,sizeof(eObj));
			return;
		}
	}
	finout.close();
}

void SequentialFile::deleteRecord(string name){
	fstream in;
	fstream out;
	out.open("temp.txt",ios::out | ios::binary);
	
    	in.open("employee.txt",ios::in | ios::binary);
	while(in.read((char*)&eObj,sizeof(eObj))){
		if(eObj.name != name){
			out.write((char*)&eObj,sizeof(eObj));
		}	
	}
	in.close();
	out.close();
	remove("employee.txt");
	rename("temp.txt","employee.txt");
}

int main(){
	cout<<"Program starting"<<endl;
	SequentialFile sf;
	//sf.readData();
	//sf.displayData();
	sf.insertRecord();
	sf.insertRecord();
	sf.displayRecord();
	cout<<"Searching: "<<endl;
	sf.searchRecord("omkar");
	cout<<"Updating: "<<endl;
	sf.updateRecord("omkar");
	sf.displayRecord();
	cout<<"Deleting: "<<endl;
	sf.deleteRecord("person");
	sf.displayRecord();
	
	return 0;

}
