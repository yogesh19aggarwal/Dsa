#include<iostream>
using namespace std;

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maximum(int *arr , int size){
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}
void countsort(int *arr , int n){
    int max = maximum(arr , n);

    int *arr1 = (int *)malloc((max+1)*sizeof(int)) ;

    for(int i=0; i<max+1; i++){
        arr1[i] = 0;
    }
    for(int i=0; i<n; i++){
        int val = arr[i];
        arr1[val] += 1; 
    }

    int i=0 , j=0;
    while(i <= max){
        if(arr1[i] > 0){
            arr[j] = i;
            arr1[i] = arr1[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    int arr[] = {57, 8, 112, 7, 2};
    int size = 5;
    display(arr, size);

    // mergesort(arr , 0 , size-1);
    countsort(arr , size);

    display(arr , size);
    return 0;
}