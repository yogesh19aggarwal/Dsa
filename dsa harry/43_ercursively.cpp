#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
class que
{
    stack<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if (s1.empty())
        {
            cout << "queue is empty " << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item = pop();
        s1.push(x);

        return item;
    }
    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    que q;
    q.push(1);
    q.push(2);

    return 0;
}