#include<iostream>
#include<vector>

using namespace std;

int findPivot(vector<int> &arr){

    int size = arr.size();
    if(size == 0){
        return -1;
    }

    int low = 0;
    int high = size-1;
    int mid;

    while(low < high){
        mid = low + (high-low)/2;

        if(arr[0] <= arr[mid]){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int binarySearch(vector<int> &arr, int s, int e, int target){

    int mid;
    while(s <= e){

        mid = s + (e-s)/2;

        if(arr[mid] == target){
            return mid;
        }

        else if(arr[mid] < target){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return -1;
}

int search(vector<int> &arr, int target){

    int pivot = findPivot(arr);
    int n = arr.size();

    if(arr[pivot] <= target && arr[n-1] >= target){
        return binarySearch(arr, pivot, n-1, target);
    }
    else{
        return binarySearch(arr, 0, pivot-1, target);
    }
}

int main(){

    return 0;
}