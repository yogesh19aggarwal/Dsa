#include <iostream>
#include <string>

using namespace std;

char getMaxOccuringChar(string str)
{
    int arr[26] = {0};
    
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        
        // int number = 0;
        // int number  = ch - 'a';
        arr[ch - 'a']++;
    }
    
    int maxi = -1 ;
    int ans = 0;

    for(int i = 0; i < 26; i++){
        if(arr[i] > maxi){
            ans = i;
            maxi = arr[i] ;
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){

    string s;

    cin>>s;

    cout<<getMaxOccuringChar(s)<<endl;

    // s.replace();
    return 0;
}