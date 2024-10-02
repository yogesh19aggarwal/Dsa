#include <bits/stdc++.h>

using namespace std;

int minMoves(vector<int>& nums) {
    int i = 0;
    int min = nums[0];
    int result = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    
    for(i = 0; i < nums.size(); i++){
        result = result + nums[i] - min;
    }
    return result;
}

int main(){

    return 0;
}