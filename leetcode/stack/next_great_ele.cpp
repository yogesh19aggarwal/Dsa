#include <vector>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{   
    vector<int> ans;
    // int size = arr.size();
    if(n == 1){
        ans.push_back(-1);
        return ans;
    }

    for (int i = 0; i < n-1; i++)
    {
        int next = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                next = arr[j];
                break;
            }
        }
        
        ans.push_back(next);
    }
    ans.push_back(-1);

    return ans;
}

int main(){

    return 0;
}