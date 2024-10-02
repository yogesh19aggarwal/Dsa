#include<iostream>
using namespace std;

void display(int *arr , int size){
    for(int i=0;i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int *arr , int size){
    int check = 0;
    for(int i = 0; i<size-1; i++){
        check =1;
        for(int j = 0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = 0;
            }
        }
        if(check == 1){
            // cout<<"array is sorted "<<endl;
            break;
        }
    }
}

void insertionsort(int *arr , int size){
    for(int i=1 ; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(arr[j] > key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        // cout<<"adress of first element";
        arr[j+1] = key;
    }
}

void selectionsort(int *arr , int size){
    for(int i = 0; i<size-1; i++){
        int min = i;
        for(int j = i+1 ; j<size ; j++){
            if(arr[min] > arr[j]){
                min =j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int partition(int *arr , int low , int high){
    int pivot , i , j;
    pivot = arr[low];
    i = low+1;
    j = high;
    do{
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}
void quicksort(int *arr , int low , int high){
    int index;
    if(low<high){
        index = partition(arr , low , high);
        quicksort(arr , low , index-1);
        quicksort(arr , index+1 , high);
    }
}

void merge(int *arr , int low , int mid , int high){
    int p[high+1] , i , j ,k;
    i = k = low;
    j = mid+1;

    while(i <= mid && j <= high ){
        if(arr[i] < arr[j]){
            p[k] = arr[i];
            i++; k++;
        }
        else{
            p[k] = arr[j];
            j++; k++;
        }
    }

    while(i <= mid){
        p[k] = arr[i];
        i++; k++;
    }
    while(j <= high){
        p[k] = arr[j];
        j++; k++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = p[i];
    }
}

void mergesort(int *arr , int low , int high){
    if(low < high){
        int mid = (low+high)/2;
        mergesort(arr , low , mid);
        mergesort(arr , mid+1 , high);
        merge(arr , low , mid , high);
    }
}
int main(){
    int arr[]= {67 , 23 , 12, 89 , 45};
    int size = sizeof(arr)/sizeof(int);

    display(arr , size);

    // bubblesort(arr , size);
    // selectionsort(arr , size);
    // insertionsort(arr , size);
    // quicksort(arr , 0 , size-1);
    mergesort(arr , 0 , size-1);

    display(arr , size);
    return 0;
}