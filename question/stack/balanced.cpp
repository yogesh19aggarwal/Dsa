#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(char ch, char top){

    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
        return true;
    }
    return false;
}

bool isValidParanthesis(string exp){

    stack<char> s;
    for(int i = 0; i < exp.length(); ++i){

        char ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else {
            if(!s.empty()){
                if(ch == ')' || ch == '}' || ch == ']'){
                    if(!isValid(ch , s.top())){
                        return false;
                    }else{
                        s.pop();
                    }
                }
            }
        }
    }
    if(!s.empty()){
        return false;
    }
    return true;
}

int main(){

    string str = "][}[";
    cout<<isValidParanthesis(str)<<endl;
    return 0;
}