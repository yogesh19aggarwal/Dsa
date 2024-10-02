#include<vector>
#include<iostream>

using namespace std;

int peak(vector<int> &arr){

    int size = arr.size();
    // int ans;
    int s = 0;
    int e = size-1;

    int mid;
    while(s < e){

        mid = s + (e-s)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid-1] > arr[mid]){
            e = mid;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr{0,10,5,2};

    cout<<peak(arr)<<endl;
    cout<<arr[peak(arr)]<<endl;
    return 0;
}