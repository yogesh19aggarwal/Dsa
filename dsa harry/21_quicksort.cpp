#include<iostream>
#include<bits/stdc++.h>
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
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int trap(vector<int>& a) {
        int n = a.size();
        int *left = new int[n];
        int *right = new int[n];
        left[0] = a[0];
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1] , a[i]);
        }
        right[n-1] = a[n-1];
        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1] , a[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += (min(left[i] , right[i]) - a[i]);
        }

        return ans;
}

int partition(int *arr , int low , int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    do{
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j]> pivot){
            j--;
        }
        if(i<j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }while(i<j);
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}
void quicksort(int *arr , int low , int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(arr , low , high);
        quicksort(arr , low , partitionIndex-1);
        quicksort(arr ,partitionIndex+1, high );
    }
}
int main(){
    int arr[] = {57,8,112,7,2};
    int size = 5;
    display(arr , size);
    // bubblesort(arr , size);
    // insertionsort(arr , size);
    quicksort(arr,0 , size-1);
    display(arr , size);
    return 0;
}