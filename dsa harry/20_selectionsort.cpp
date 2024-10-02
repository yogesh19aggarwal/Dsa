#include<iostream>
using namespace std;
void display(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertionsort(int *arr , int size){
    for(int i = 1; i<size ; i++){
        int store = arr[i];
        int j=i-1;
        while(store<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = store;
    }
}
void bubblesort(int *arr , int size){
    int isSorted = 0;
    for(int i=0; i<size-1; i++){
        // cout<<"pass number : "<<i+1<<endl;
        isSorted = 1;
        for(int j=0; j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}
void selectionsort(int *arr , int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int arr[] = {57,8,112,7,2};
    int size = 5;
    display(arr , size);
    // bubblesort(arr , size);
    // insertionsort(arr , size);
    selectionsort(arr , size);
    display(arr , size);
    return 0;
}