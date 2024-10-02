#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int> &st, int count, int size){
     
    if(count == size/2){
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    
    solve(st, count+1, size);

    st.push(temp);
}

void deleteMiddle(stack<int> &inputStack, int N){

    int count = 0;
    solve(inputStack, count, N);
}

int main(){

    return 0;
}