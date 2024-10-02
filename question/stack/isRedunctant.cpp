#include<iostream>
#include<stack>

using namespace std;

bool isReduntant(string &s){

    stack<char> st;

    for(int i = 0; i < s.length(); ++i){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '/'|| ch == '*'){
            st.push(ch);
        }else{

            if(ch == ')'){
                bool isReduntant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '/'|| top == '*'){
                        isReduntant = false;
                    }
                    st.pop();
                }
                if(isReduntant){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){

    return 0;
}