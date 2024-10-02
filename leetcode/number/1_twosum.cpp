#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int size;
    cout<<"enter the size of array : ";
    cin>>size;

    // initialize the array
    vector<int> arr(size);
    int element;
    // input the values of array
    cout<<"enter the values of array"<<endl;
    for(auto &i : arr){
        cin>>i;
    }
    cout<<endl;

    // output the values
    for(auto &i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    int target;
    cout<<"enter the target : ";
    cin>>target;

    // int i;
    // int j;
    int count = 0;

    // for(i=0; i<size; i++){
    //     for(j=i+1; j<size; j++){
    //         if(arr[i]+arr[j] == target){
    //             count = 1;
    //             cout<<"target is found"<<endl;
    //             cout<<"["<<i<<","<<j<<"]";
    //             break;
    //         }
    //     }
    // }
    
    sort(arr.begin() , arr.end());

    int low = 0;
    int high = size-1;
    while(low < high){
        if(arr[low] + arr[high] == target){
            count = 1;
            cout<<"target is found"<<endl;
            cout<<"["<<low<<","<<high<<"]";
            break;
        }
        else if(arr[low] + arr[high] < target){
            low++;
        }
        else{
            high--;
        }
    }


    // if(count == 1){
    //     cout<<"target is found"<<endl;
    //     cout<<"["<<i<<","<<j<<"]";
    // }
    // else{
    //     cout<<"target is not found"<<endl;
    // }
    return 0;
}