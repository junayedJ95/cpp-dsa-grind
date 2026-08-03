#include<iostream>
using namespace std;

struct myArray
{
    int totalsize;
    int usedsize;
    int *ptr;

};

void createArray(struct myArray *a, int tsize, int usize){
    a->totalsize = tsize;
    a->usedsize = usize;
    a->ptr = new int[tsize];
}

void show(struct myArray *a){
    for(int i=0; i<a->usedsize; i++){
        cout<<a->ptr[i]<<" ";
    }
    cout<<endl;
}

int main(){

struct myArray marks;
createArray(&marks, 10, 2);


cout<<"Total size: "<<marks.totalsize<<endl;
cout<<"Used size: "<<marks.usedsize<<endl;

return 0;
}