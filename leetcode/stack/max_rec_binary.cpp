#include <stack>
#include <vector>
#include <iostream>
// #include <algorithm>
// #include <cmath>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);

    stack<int> s;

    s.push(-1);

    for (int i = n - 1; i >= 0; --i)
    {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        arr[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{

    vector<int> ans(n);

    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; ++i)
    {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangle(vector<int> &heights){

    int n = heights.size();
    int area = INT_MIN;

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    for(int i = 0; i < n; ++i){

        int l = heights[i];

        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l*b;
        int area = max(area, newArea);
    }

    return area;
}

int maxArea(vector<vector<int> >M, int n, int m){

    int area = largestRectangle(M[0]);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(M[i][j] != 0)
                M[i][j] = M[i][j] + M[i-1][j];
            else{
                M[i][j] = 0;
            }
        }
        area = max(area, largestRectangle(M[i]));
    }

    return area;
}

int main()
{

    return 0;
}