#include<iostream>
using namespace std;

int myAtoi(string s){
    int sign = 1;
    double ans=0;
    int a=0;
    int len = s.size();
    int i = 0;
    while(s[i] == ' '){
        i++;
    }
    if(s[i] == '+'){
        sign = 1;
        a += 1;
        i++;
    }
    if(s[i] == '-'){
        sign = -1;
        a += 1;
        i++;
    }
    if(a==2){
        return 0;
    }
    
    while(i<len && s[i] >='0' && s[i] <='9' ){
        ans = ans*10 + (s[i] - '0');
        i++;
    }
    ans *= sign;
    if(ans > INT_MAX){
       ans = INT_MAX;
    }
    if(ans < INT_MIN){
       ans = INT_MIN;
    }
    return int(ans);
}
int main(){
    string s = "+-1";
    cout<<myAtoi(s);
   
    return 0;
}