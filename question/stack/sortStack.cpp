#include<iostream>
#include<stack>

using namespace std;

void insertAtSort(stack<int> &st, int num){

    if(st.empty() || st.top() <= num){
        st.push(num);
        return;
    }
    int val = st.top();
    st.pop();
    insertAtSort(st, num);
    st.push(val);
}

void sortStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);
    insertAtSort(st, num);
}

int main(){

    return 0;
}