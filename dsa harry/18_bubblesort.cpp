#include<iostream>
using namespace std;
void display(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int *arr , int size){

    int isSorted = 0;

    for(int i=0; i<size-1; i++){
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
int main(){
    int arr[] = {3,4,7,9,35,39};
    int size = 6;
    display(arr , size);
    bubblesort(arr , size);

    display(arr , size);
    return 0;
}