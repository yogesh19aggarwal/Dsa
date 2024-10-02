#include<iostream>
#include<queue>

using namespace std;

void solve(queue<int> &q){

    if(q.empty()){
        return;
    }

    int num = q.front();
    q.pop();
    solve(q);

    q.push(num);
}

queue<int> rev(queue<int> q){

    solve(q);

    return q;
}

void traversal(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<", ";
        q.pop();
    }cout<<endl;
}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.size()<<endl;

    // cout<<"before reverse: ";
    // traversal(q);
    // cout<<endl;

    // queue<int> qt = rev(q);
    // cout<<"after reverse: ";
    // traversal(qt);
    // cout<<endl;

    return 0;
}