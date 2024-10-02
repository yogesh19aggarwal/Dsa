#include<iostream>
using namespace std;

bool isPalindrome(int num) {
    int n = num;
    int rev = 0;
    // int dig;
    while (num > 0)
    {
        // dig = num%10;
        rev = rev * 10 + num%10;
        num = num / 10;
    }   
    if(n == rev){
        return true;
    }     
    else{
        return false;
    }
}
int main(){
    
    return 0;
}