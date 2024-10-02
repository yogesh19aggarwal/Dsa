#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextSmaller(vector<int> &arr, int n){

    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--){

        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}
vector<int> prevSmaller(vector<int> &arr, int n){

    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++){

        int curr = arr[i];

        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }
 
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int largestArea(vector<int> &arr){

    int n = arr.size();

    vector<int> next = nextSmaller(arr, n);
    vector<int> prev = prevSmaller(arr, n);

    int area = INT_MIN;

    for(int i = 0; i < n; ++i){
        int l = arr[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(newArea, area);
    }

    return area;
}

int main(){

    vector<int> height{2,1,5,6,2,3};
    cout<<largestArea(height);

    return 0;
}