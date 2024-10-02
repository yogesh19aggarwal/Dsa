// #include <bits/stdc++.h> 
#include <stack>

using namespace std;

void solve(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, x);

    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // stack<int> temp;

    // while(!myStack.empty()){
    //     temp.push(myStack.top());
    //     myStack.pop();
    // }

    // myStack.push(x);
    // while(!temp.empty()){
    //     myStack.push(temp.top());
    //     temp.pop();
    // }

    solve(myStack, x);

    return myStack;
}

int main(){

    return 0;
}