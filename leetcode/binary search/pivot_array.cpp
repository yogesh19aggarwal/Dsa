#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int> arr){

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

    return arr[low];
}

int main(){

    vector<int> arr = {7,9,1,2,3};
    cout<<pivot(arr)<<endl;
    // cout<<"hello";

    return 0;
}