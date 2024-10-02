#include<iostream>
#include<stack>
using namespace std;

string reverse(string s){

    stack<string> st;
    
    for(int i=0; i<s.length(); i++){
        string word = "";
        while(s[i] != ' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    string s1 = "";
    while(!st.empty()){
        s1 += st.top();
        s1 += " ";
        st.pop();
    }

    return s1;
}

void insertAtBottom(stack<int> st , int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st , ele);

    st.push(topele);
}

void reverseStack(stack<int> st){
    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st , ele);
    
}
int main(){
    string s = "hii , what are you doing?";
    cout<<s<<endl;
    s = reverse(s);
    cout<<s<<endl;


    return 0;
}