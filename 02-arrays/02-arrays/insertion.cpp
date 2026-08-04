#include<iostream>
using namespace std;


void display(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int indinsertion(int arr[], int size, int element, int capacity, int index_){
   
    if(size>=capacity){
        return -1;
    }
for(int i = size-1; i>=index_; i--){
    arr[i+1] = arr[i];
}
    arr[index_] = element;

return 1;

}


int main(){
     int arr[100] = {7,8,12,27, 88};
     int size = 5;
    
     int element = 45;
     int index_ = 5;

     display(arr,size);

int result = indinsertion(arr, size, element, 100, index_);

if(result == 1){
    cout << "Insertion Successful!" << endl;
    size++;
}
else{
    cout << "Insertion Failed! Array is Full." << endl;
}
     
     display(arr,size);

     return 0;  
}
