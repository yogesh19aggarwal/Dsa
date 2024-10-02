#include <iostream>
#include <string>
using namespace std;

string reverse(string s){
    int n = s.length();
    string s1 = s ;
    for(int i = 0; i<n/2; i++){
        // s1[i] += s[n-i-1];
        swap(s1[i] , s1[n-i-1]);
    }
    return s1;
}
int main(){
    // string s = "424244234234";
    // int n = s.size();
    // for(int i=0; i<n-1; i++){
    //     for(int j = 0; j<n-1-i; j++){   
    //         if(s[j] < s[j+1]){
    //             int temp = s[j];
    //             s[j] = s[j+1];
    //             s[j+1] = temp;
    //         }
    //     }
    // }

    string s1 = "hello world";
    string s = reverse(s1);
    cout<<s<<endl;
    return 0;
}