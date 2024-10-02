#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class hero{
    int i;
    short s;
    char c;
    double d;
    int sa;
};

bool isPossible(vector<int> &arr, int k, int mid){

    int cowCount = 1;

    int lastPos = arr[0];

    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int aggressivecows(vector<int> &arr, int k){
    
    sort(arr.begin(), arr.end());
    int s = 0;
    int maxi = -1;

    for(int i = 0; i < arr.size(); ++i){
        maxi = max(maxi, arr[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s <= e){
        if(isPossible(arr, k, mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    } 
    return ans;
}

int main(){

    hero b;
    cout<<sizeof(b);
    return 0;
}