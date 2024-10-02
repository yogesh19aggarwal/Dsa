#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
    vector<string> a(numRows , ""); 
    int i=0;
    int n = s.length();

    while(i < n){
        for(int j = 0; j<numRows && i<n; j++){
            a[j].push_back(s[i]);
            i++;
        }

        for(int j = numRows-2; j >= 1  && i<n; j--){
            a[j].push_back(s[i]);
            i++;
        }
    }
    string res = "";
    for(auto i : a){
        res += i;
    }
    return res;
}

int reverse(long long n){
    // int a = n;
    long long rev = 0;
    while(n != 0)
    {
        rev = rev*10 + n%10;
        n = n/10;
    }
    if(rev > (INT32_MAX/2)){
        return 0;
    }
    if(rev < (INT32_MIN/2)){
        return rev;
    }
    return int(rev);
}
// INT_FAST32_MAX;
int main(){
    cout<<reverse(429496722);
    return 0;
}