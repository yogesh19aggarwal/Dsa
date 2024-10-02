#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &arr, int k, int mid){
    
    int cowCount = 1;
    int lastPos = arr[0];

    for(int i = 0; i < arr.size(); i++){
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

int aggressiveCows(vector<int> &stalls, int k)
{
    int s = 0;
    sort(stalls.begin(), stalls.end());

    int maxi = -1;

    for(int i = 0; i < stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }

    int e = maxi; 

    int ans = -1;
    int mid = s + (e-s)/2;

    while(s <= e){
        
        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid+1;
        }

        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main(){

    return 0;
}