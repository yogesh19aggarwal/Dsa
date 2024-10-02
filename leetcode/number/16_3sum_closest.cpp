#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        
    sort(nums.begin(), nums.end());

    int diff = INT_MAX;

    int ans;

    for(int i = 0; i < nums.size(); i++){

        int first = nums[i];
        int start = i+1;
        int end = nums.size()-1;

        while(start < end){
            if( ( first + nums[start] + nums[end] ) == target ){
                return target;
            }
            
            else if( abs(first + nums[start] + nums[end] - target ) < diff ){

                diff = abs(first + nums[start] + nums[end] - target);
                ans = first + nums[start] + nums[end];
            }

            if(( first + nums[start] + nums[end] ) > target ){
                end--;
            }

            else{
                start++;
            }
        } 
    }
    
    return ans;
}

int main(){

    char a[] = "abc10b";
    string s = "abc10b";

    cout<<"character array : "<<a<<endl<<" string : "<<s<<endl;

    
    return 0;
}