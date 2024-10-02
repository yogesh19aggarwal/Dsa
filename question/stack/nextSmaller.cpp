#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextSmaller(vector<int> &arr, int n){

    stack<int> st;
    vector<int> ans(n);

    st.push(-1);

    for(int i = n-1; i >= 0; --i){
        int curr = arr[i];

        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}
vector<int> prevSmaller(vector<int> &arr, int n){

    stack<int> st;
    vector<int> ans(n);

    st.push(-1);

    for(int i = 0; i < n; ++i){
        int curr = arr[i];

        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

int main(){

    return 0;
}