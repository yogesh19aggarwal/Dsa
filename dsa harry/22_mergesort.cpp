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

void mergeDiffArr(int *arr, int *arr1, int *arr2, int m, int n)
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void merge(int *arr, int mid, int low, int high)
{
    int i, j, k, arr1[high+1];
    i = low;
    j = mid + 1;
    k=low;
    
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr1[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr1[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arr1[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = arr1[i];
    }
}
void mergesort(int *arr , int low , int high){
    int mid;
    if(low < high){
        mid = (low+high)/2;
        mergesort( arr , low , mid);
        mergesort(arr , mid+1 , high);
        merge(arr , mid , low , high);
    }
}
int main()
{
    int arr[] = {57, 8, 112, 8, 2};
    int size = 5;
    display(arr, size);

    mergesort(arr , 0 , size-1);
    display(arr , size);
    return 0;
}