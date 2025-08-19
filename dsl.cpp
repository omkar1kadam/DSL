#include<iostream>
using namespace std;

class student {
	private:
		int data[1000];
		int size;
	public:
		void fill_input(){
			cout << "Enter the total number of students: ";
			cin>>size;
			for (int i = 0; i<size; i++) {
				cout << "enter the " << i << "th student roll no. :";
				cin >> data[i];
			}
			cout << "Filling completed! " << endl;
		}

		void show_details(){
			for(int i = 0; i<size; i++) {
				cout << i+1 << "th student roll no is :" << data[i] << endl;
			}
		}

		int linear_search(int target){
			for (int i=0; i<size; i++) {
				if (target == data[i]){
					return i;
				}
			}
			return -1;
		}
		int binary_search(int target){
			int lower = 0;
    			int upper = size - 1;

			while (lower <= upper){
				int mid = (lower + upper)/2;

				if (target == data[mid]) {
					return mid;
				}
				else if (target > data[mid]){
					lower = mid +1;
				}
				else {
					upper = mid -1;
				}
			}
			return -1;
		}
		void bubble_sort(){
			cout<< "Before sorting" << endl;
			show_details();
			
			bool isSorted;
			for(int i=0; i<size; i++){
				isSorted = true;
				for(int j=0; j<size-i-1; j++){
					if (data[j] <= data[j+1]){
						isSorted = false;
						
						int temp;
						temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
					// cout << "value of i and j are" << i << j << endl; 
				}
				if (isSorted){
					break;
				}
			}
			
			cout<< "After sorting" << endl;
			show_details();
		}
		void selection_sort(){
			cout<< "Before sorting" << endl;
			show_details();
			
			bool isSorted;
			for(int i=0; i<size; i++){
				isSorted = true;
				for (int j=i+1; j<size-1;j++){
					if (data[i] <= data[j]){
						isSorted = false;
						int temp;
						temp = data[i];
						data[i] = data[j];
						data[j] = temp;
					} 
				}
				if (isSorted){
					break;
				}
			}
			cout<< "After sorting" << endl;
			show_details();
		}
		void print_top_5_scores(int which_sort){
			if (which_sort == 1){
				bubble_sort();
			}
			else if (which_sort == 2){
				selection_sort();
			}
			
			// printing the top 5 elements
			if (size >= 5){
				for (int i=0; i<5; i++){
					cout << data[i] << endl;
				}
			}
			else if (size == 0){
				cout << "There are no students " << endl;
			}
			else if (size <5){
				for (int i=0; i<size; i++){
					cout << data[i] << endl;
				}
			}
		}
};

int main() {
	student stud;

	int choice;
	while (choice !=99) {
		cout << "********** Welcome the the student database ********** \n" << endl;
		cout << " Enter 1 for filling in the student details" << endl;
		cout << " Enter 2 for fetching the students details"  << endl;
		cout << " Enter 3 for linear search " << endl;
		cout << " Enter 4 for binary search " << endl;
		cout << " Enter 5 for Bubble Sort " << endl;
		cout << " Enter 6 for Selection Sort " << endl;
		cout << " Enter 7 for top 5 Scores " << endl;
		cout << " Enter 99 for exiting " << endl;
		cout << " Enter your choice : ";
		cin >> choice;

		if (choice == 1) {
			stud.fill_input();
		}
		else if (choice == 2) {
			stud.show_details();
		}
		else if (choice == 3) {
			int target;
			cout << "Enter the value you wanna search";
			cin >> target;
			int index = stud.linear_search(target);
			cout << "Rollno is  at " << index << "th index" << endl;
		}
		else if (choice == 4) {
			int target;
			cout << "Enter the value you wanna search";
			cin >> target;
			int index = stud.binary_search(target);
			cout << "Rollno is  at " << index << "th index" << endl;
		}
		else if (choice == 5){
			stud.bubble_sort();
		}
		else if (choice == 6){
			stud.selection_sort();
		}
		else if (choice == 7){
			cout << " Enter 1 for bubble sort" <<  endl;
			cout << " Enter 2 for selection sort " << endl;
			int sort_choice;
			cin >> sort_choice;
			stud.print_top_5_scores(sort_choice);
		}
		else if (choice == 99) {
			cout << "exiting" << endl;
		}
		else {
			cout << "enter a valid number" << endl;
			
		}
	}
}

// update 
