#include <bits/stdc++.h>

using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{

    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    solve(str, output, index + 1, ans);

    char element = str[index];
    output += element;

    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string output = "";

    int index = 0;

    solve(str, output, index, ans);

    for (auto i : ans)
    {

        cout << i << endl;
    }
}

int main()
{
    
  int a = 10;
  int x = (++a) + (++a);
  cout<<x;
  return 0;
}

//     return 0;
// }