#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int indinsertarr(int arr[], int &size, int index, int capacity, int element){
    if(size>=capacity){
        return -1;
    }
    else{
        for(int i=size-1; i>=index; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        size++;
        return 1;
    }
}
int inddeletearr(int arr[], int &size, int index){
    int val;
    val = arr[index];
    for(int i = index; i<size; i++){
        arr[i] = arr[i+1];
    }
    size--;
    return val;
}
int main(){
    int arr[100] = {7,8,12,27,88};
    int size = 5, element = 45; 
    int index;
    cout<<"enter the index : ";
    cin>>index;
    display(arr , size);
    cout<<endl;
    indinsertarr( arr,  size,  index,  100,  element);
    display(arr , size);
    inddeletearr(arr, size, index);
    display(arr, size);

    return 0;
}