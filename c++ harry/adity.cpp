#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float largestTriangle(float base1, float height1, float base2, float height2){

    float tri1; 
    float tri2;

    tri1 = (base1*height1)/2;
    tri2 = (base2*height2)/2;
    if(tri1 > tri2){
        return tri1;
    }
    else{
        return tri2;
    }

}

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>>ans;
    // ans.push_back();
    int size = arr.size();
    if(size == 0){
       return ans;
    }

   sort(arr.begin() , arr.end());
   // int mid = size/2;
   int i = 0;
   int j = size-1;
   while( i < j ){
    // cout<<i<<" "<<j<<endl;
        if(arr[i]+ arr[j] == s){
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);
            i++;
            j--;
        }
        else if(arr[i] + arr[j] < s){
            i++;
        }
        else{
            j--;
        }
   }

   return ans;
}


int main(){

    // cout<<largestTriangle(5 , 3 , 3 , 7);
    // cout<<editorMiss("aa abc@ sad$ hsagd^");

    // vector<int> arr = {1, 2, 3, 4, 5};

    // int s = 5;
    // vector<vector<int>> sum;
    // sum = pairSum(arr, s);

    // // cout<<"hello:";
    // for(auto i : sum){
    //     for(auto j : i){
    //         cout<<j<<", ";
    //     }cout<<endl;
    // }
    // cout<<"helo";

    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int size = sizeof(arr)/ sizeof(arr[0]);
    // printf("%lu", sizeof(arr[0]));

    cout<<size<<endl;
    return 0;
}