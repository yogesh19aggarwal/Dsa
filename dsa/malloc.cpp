#include<iostream>
// #include<stdlib.h>

using namespace std;

int main(){

    int *ptr;

    int size;
    cout<<"enter the size : ";
    cin>>size;

    ptr = (int*) malloc(size * sizeof(int));

    for(int i=0; i<size;i++){
         cout<<"enter the value of array at "<<i<<" : ";
        cin>>ptr[i];
    }
    for(int i=0; i<size; i++){
        cout<<"valur of arr at position "<<i+1<<" : "<<ptr[i]<<endl;
    }

    return 0;
}