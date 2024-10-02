#include<bits/stdc++.h>
#include<iostream>

using namespace std;

vector<vector<int>> threesum(vector<int> a){
    vector<vector<int>> b;
    int n = a.size();

    // brute force

    // for(int i = 0; i < n-2; i++){
    //     for(int j = i+1; j < n-1; j++){
    //         for(int k = j+1; k < n; k++){
    //             if(a[i] + a[j] + a[k] == 0){
    //                 vector<int>r = {a[i] , a[j] , a[k]};
    //                 b.push_back(r);
    //             }
    //         }
    //     }
    // }
}

    // optimal   

        // two pointer approach
vector<vector<int>> threeSumO(vector<int>& a) {
    vector<vector<int>> b;
    int n = a.size();
    sort(a.begin() , a.end());
    for(int i = 0; i<n-2; i++){
        if( i == 0 || (a[i] != a[i-1]))
        {   
            int target = -a[i];
            int low = i+1, high = n-1;
            while(low < high)
            {   
                if(a[low] + a[high] == target ){
                    vector<int> c = {a[i] , a[low] , a[high]};
                    b.push_back(c);
                    while(low < high && a[low] == a[low +1]){
                        low++;
                    }   
                    while(low < high && a[high] == a[high - 1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(a[low] + a[high] > target){
                    high--;
                }
                else{
                    low++;
                }
                
            }
        }
    }
    return b;
}

int main(){
    vector<vector<int>> a;
    
    // a[0].push_back(5);
    // for(int i=0; i<a.size(); i++){
    //     for(int j = 0; a[i].size(); j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<endl;
    // }
    return 0;
}