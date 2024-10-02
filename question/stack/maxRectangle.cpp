#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define MAX 1000

vector<int> prevSmallest(int *arr, int n){

    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i = 0; i < n; ++i){

        int curr = arr[i];

        while(curr <= arr[st.top()] && st.top() != -1){
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

vector<int> nextSmallest(int *arr, int n){

    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i = n-1; i >= 0; --i){

        int curr = arr[i];

        while(curr <= arr[st.top()] && st.top() != -1){
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

int largestRectangle(int *arr, int n){

    vector<int> prev = prevSmallest(arr, n);
    vector<int> next = nextSmallest(arr, n);

    int area = INT_MIN;
    for(int i = 0; i < n; ++i){
        int l = arr[i];

        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int subArea = l * b;

        area = max(subArea, area);
    }

    return area;
}

int maxArea(int M[MAX][MAX], int n, int m){

    int area = largestRectangle(M[0], m);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){

            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }else{
                M[i][j] = 0;
            }
        }
        area = max(area, largestRectangle(M[i], m));
    }

    return area;
}

int main(){

    
    return 0;
}