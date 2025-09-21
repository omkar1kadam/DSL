// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr,int left,int mid,int right){
    //preparing the left array and the right array 
    int n1 = mid-left+1;
    int n2 = right-mid;
    
    vector<int> L(n1),R(n2);
    
    for(int i=0; i<n1;i++){
        L[i] = arr[left + i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[mid+1+j];
    }
    
    int i=0,j=0;
    int k = left;
    
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr,int left,int right){
    if (left >= right){
        return;
    }
    
    int mid = (left + right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr,left,mid,right);
}
int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    int size = 9;
    cout << "Before Sorting:"  ;
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << " " << endl;
    
    mergeSort(arr,0,8);
    cout << "After Sorting:"  ;
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << " " << endl;
    

    return 0;
}
