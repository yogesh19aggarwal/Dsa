#include<bits/stdc++.h>

using namespace std;

vector<int> subArraySum(vector<int> arr, int n, long long s){

    
    vector<int> ans;

    int start = 0;

    int low = 0;
    int high = 0;
    
    bool flag = 0;
    long long sum = 0;

    for(int i = 0; i < n; i++){

        sum += arr[i];

        while(sum > s){
            sum -= arr[start];
            start++;
        }

        if(sum == s){
            flag = 1;
            low = start+1;
            high = i+1;
            break;
        }
    }

    if(flag && low <= high){
        ans.push_back(low);
        ans.push_back(high);
    }else{
        ans.push_back(-1);
    }

    return ans;
}

int main(){

    

    return 0;
}