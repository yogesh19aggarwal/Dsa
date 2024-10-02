#include<iostream>
#include<vector>

using namespace std;

long long int binarySearch(int n){

    int s = 0;
    int e = n;

    long long int mid = s + (e-s)/2;
    int ans;
    while(s < e){

        long long sq = mid * mid;

        if(sq == n){
            return mid;
        }
        else if(sq < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }

    return -1;
}

int main(){
    
    return 0;
}