#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid){

    int student = 1;

    int pageSum = 0;

    for(int i = 0; i < n; ++i){

        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            student++;
            if(student > m || arr[i] > mid){
                return false;
            }
            // pageSum = 0;
            pageSum = arr[i];
        }
    }

    return true;
}

int allocate(vector<int> arr, int n, int m){

    int s = 0;
    int sum = 0;

    for(int i = 0; i < n; ++i){
        sum += arr[i];
    }

    int ans = -1;

    int e = sum;

    int mid = s + (e - s)/2;

    while(s <= e){
        if(isPossible(arr, n, m ,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e - s)/2;
    }

    return ans;
}

int main(){

    return 0;
}