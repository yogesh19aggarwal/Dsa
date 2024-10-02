#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int n){

    int celeb = -1;
    for(int i = 0; i < n; ++i){

        bool rowCheck = true;
        bool colCheck = true;

        for(int j = 0; j < n; ++j){
            if(M[i][j] != 0){
                rowCheck = false;
            }
        }
        for(int j = 0; j < n; ++j){
            if(M[i][j] != 1 && i != j){
                colCheck = false;
            }
        }

        if(rowCheck && colCheck){
            celeb = i;
        }
    }
    return celeb;
}

int celebrity2(vector<vector<int>> &M, int n){

    stack<int> st;

    for(int i = 0; i < n; ++i){
        st.push(i);
    }

    while(st.size() > 1){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(M[a][b] == 1){
            st.push(b);
        }else{
            st.push(a);
        }
    }

    int cel = st.top();
    st.pop();

    bool rowCheck = true;
    bool colCheck = true;
    
    for(int j = 0; j < n; ++j){
        if(M[cel][j] != 0){
            rowCheck = false;
        }
    }
    for(int j = 0; j < n; ++j){
        if(M[j][cel] != 1 && cel != j){
            colCheck = false;
        }
    }

    if(rowCheck && colCheck){
        return cel;
    }
    return -1;
}

int main(){

    return 0;
}