#include<iostream>
#include<string>
#include<stack>

using namespace std;

string reverseString(string str){

    stack<char> s;

    int size = str.length();
    for(int i = 0; i < size; ++i){
        s.push(str[i]);
    }

    string ans = "";
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main(){

    string str = "yogesh";

    string reverse = reverseString(str);
    cout<<reverse<<endl;
    return 0;
}