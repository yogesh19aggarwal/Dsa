#include<iostream>
#include<stack>

using namespace std;

void insertAtLast(stack<int> &st, int val){

    if(st.empty()){
        st.push(val);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtLast(st, val);

    st.push(num);
}

void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();
    reverse(st);

    insertAtLast(st, num);
}

void print(stack<int> &st){

    if(st.empty()){
        return;
    }

    int num = st.top();
    cout<<num<<", ";
    st.pop();

    print(st);

    st.push(num);
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    print(st);
    cout<<endl;

    reverse(st);

    print(st);
    cout<<endl;

    
    return 0;
}