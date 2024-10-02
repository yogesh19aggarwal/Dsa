#include<iostream>
#include<vector>
using namespace std;


int totalSum(int arr[], int sum, int size){
    if(size == 0){
        return sum;
    }

    if(size == 1){
        return sum+arr[0];
    }

    sum += arr[0];

    return totalSum(arr+1, sum, size-1);
}

void printSuper(vector<int> &arr){
    
    

}

int main(){

    int arr[] = {1,2,3,4,5};

    cout<<totalSum(arr, 0, 5);
    return 0;
}