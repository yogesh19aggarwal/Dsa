#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(char ch){

    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ){

        return true;
    }

    return false;
    }

    char upperToLower(char c){

        if(c >= 'A' && c <= 'Z'){
            c = c-'A' + 'a';
        }
        return c;
    }

    bool checkPalindrome(string s){

        int low = 0;
        int high = s.length()-1;

        while(low < high){

            if(s[low++] != s[high--]){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {

       int i = 0;

       string temp = "";

       for(int j = 0; j < s.length(); j++){

           if(isValid(s[j])){
            
               temp.push_back(s[j]);
           }
       } 
       
        //  to lower
        for(int j = 0; j < temp.length(); j++){
            temp[j] = upperToLower(temp[j]);
        }

        return (checkPalindrome(temp));
       
    }

int main(){

    return 0;
}