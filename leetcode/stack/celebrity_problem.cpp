#include <stack>
#include <vector>

using namespace std;

bool knows(vector<vector<int>> &M, int a, int b)
{

    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    for (int i = 0; i < n; ++i)
    {
        s.push(i);
    }

    while (s.size() > 1) // != 1
    {

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();

    // bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; ++i)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }

    if (zeroCount != n)
    {
        // rowCheck = true;
        return -1;
    }

    // bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; ++i)
    {
        if (M[i][ans] == 1)
        {
            oneCount++;
        }
    }

    if (oneCount != n - 1)
    {
        // colCheck = true;
        return -1;
    }

    // if(rowCheck == true && colCheck == true){
    return ans;
    // }
    // else{
    // return -1;
    // }
}

int main()
{

    return 0;
}