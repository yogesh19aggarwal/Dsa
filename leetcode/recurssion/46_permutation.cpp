#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;
void solve(vector<int>& nums , int idx) {
    
    if(idx == nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int i = idx; i < nums.size(); i++){
        swap(nums[i] , nums[idx]);
        solve(nums , idx+1);
        swap(nums[i] , nums[idx]);
    }
    return ;
    }
    
vector<vector<int>> permute(vector<int>& a) {
    vector<int>p;
    solve(a,0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a){
        cin>>i;
    }
    
    return 0;
}