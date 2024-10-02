#include <iostream>
#include <vector>

using namespace std;

int getPivot(vector<int> arr){

    int size = arr.size();
    int low = 0;
    int high = size-1;
    int mid ;
    while(low < high){
        mid = low + (high-low)/2;
        if(arr[mid] >= arr[0]){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int binarySearch(vector<int> arr, int low, int high, int key){
    
    int mid = low + (high-low)/2;
    while(low <= high){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            high--;
        }
        else{
            low++;
        }
        mid = low + (high-low)/2;
    }
    return -1;
}

int search(vector<int>& arr, int target) {
    int n = arr.size();

    int pivot = getPivot(arr);
    
    if(target >= arr[pivot] && target <= arr[n-1]){
        
        return binarySearch(arr, pivot, n-1, target);
    }
    else{
        return binarySearch(arr, 0, pivot-1, target);
    }
}   

int main(){

    return 0;
}