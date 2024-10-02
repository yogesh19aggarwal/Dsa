#include <iostream>
using namespace std;

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// SELECTION SORT
void selectionsort(int *arr, int size)
{
    for(int i = 0; i<size-1; i++){
        int min = i;
        for(int j = i+1; j<size; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp; 
    }

}

// BUBBLE SORT
void bubblesort(int *arr, int size)
{
    for(int i=0; i<size-1; i++){
        for(int j = 0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// INSERTION SORT
void insertionsort(int *arr, int size)
{
    for(int i = 1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(arr[j] > key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// QUICKSORT
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    while(i<j){
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
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}
void quicksort(int *arr, int low, int high)
{
    int index;
    if(low<high){
        index = partition(arr , low , high);
        quicksort(arr , low , index-1);
        quicksort(arr , index+1, high);
    }
}

// MERGE SORT
void merge(int *arr , int low , int mid , int high){
    int arr1[high+1] , i , j , k;
    i = low;
    j = mid+1;
    k=low;
    while(i <= mid && j<=high){
        if(arr[i] < arr[j]){
            arr1[k] = arr[i];
            k++; i++;
        }
        else{
            arr1[k] = arr[j];
            k++;j++;
        }
    }
    while(i<=mid){
        arr1[k] = arr[i];
        k++; i++;
    }
    while(j<=high){
        arr1[k] = arr[j];
        k++;j++;    
    }
    for(i=low; i <= (high); i++){
        arr[i] = arr1[i];
    }
}
void mergesort(int *arr , int low , int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(arr , low , mid);
        mergesort(arr , mid+1 , high);
        merge(arr , low , mid , high);   
    }
}

// COUNT SORT
void countsort(int *arr , int size){
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

    int p[max+1];

    for(int i=0; i<=max; i++){
        p[i] = 0;
    }

    for(int i=0; i<size; i++){
        int val = arr[i];
        p[val] += 1;
    }

    int m=0;
    int n=0;
    while(m<=max){
        if(p[m] == 0){
            m++;
        }
        else{
            arr[n] = m;
            n++;
            p[m]--;
        }
    }
}

int main()
{
    int arr[] = {57, 8, 112, 8, 2};
    int size = 5;
    display(arr, size);
    // bubblesort(arr , size);
    // insertionsort(arr , size);
    // quicksort(arr, 0, size - 1);
    // selectionsort(arr , size);
    // mergesort(arr ,0, size-1);
    countsort(arr , size);

    display(arr, size);
    return 0;
}