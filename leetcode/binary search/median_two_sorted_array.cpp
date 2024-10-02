#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

double indMedianSortedArrays(vector<int>& arr, vector<int>& arr1) {
    int size1 = arr.size();
    int size2 = arr1.size();
    int n =size1+size2;
    vector<int> a(n);
    int k=0;
    int i=0 , j=0;
    while(i<size1 && j<size2){
        if(arr[i] < arr1[j]){
            a[k] = arr[i];
            i++;k++;
        }
        else{
            a[k] = arr1[j];
            j++;k++;
        }
    }
    while(i<size1){
        a[k] = arr[i];
        i++;k++;
    }
    while(j<size2){
        a[k] = arr1[j];
        j++;k++;
    }
    int m ,m2 ;
    int low = 0;
    int high = a.size()-1;
    float median;
    if(high%2 == 0){
        m = (low+high)/2.0;
        median = a[m];
    }
    else{
        m = (low+high)/2;
        m2 = (low+high+1)/2;
        median = (a[m]+a[m2])/2.0;
    } 
    return median;
}
string longestPalindrome(string s) {
        
}
int main(){
    
    string s = "abcd";
    set<char> b;

    for(int i = 0; i < s.size(); i++){
        b.insert(s[i]);
    }

    int c = 0;
    set<char>:: iterator it;
    for(it = b.begin(); it != b.end(); it++){
        c = c+1;
    }
    cout<<b.size();
    return 0;
}

// int get_hash(char c)
// {
//     return c - 'a';
// }
// a, b, c, d, e, f, ..., z
// 26 -> 
// a -> 0
// b -> 1
// c -> 2


// z -> 25

// vector<int> cache(26, 0);

// cache[s[i] - 'a']++