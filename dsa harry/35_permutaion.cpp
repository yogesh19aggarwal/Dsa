#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> permute(vector<int>& nums , int idx){
    vector<vector<int>> ans;
    if(idx == nums.size()){
        ans.push_back(nums);
        return ans;
    }
    for(int i = idx; i < nums.size(); i++){
        swap(nums[i] , nums[idx]);
        permute(nums , idx+1);
        swap(nums[i] , nums[idx]);
    }
    return ans;
}

int main(){
    
    return 0;
}