#include <bits/stdc++.h>

using namespace std;

int maxProfit0(vector<int> &prices)
{ // brute force
    int max = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (max < (prices[j] - prices[i]))
            {
                max = (prices[j] - prices[i]);
            }
        }
    }
    return max;
}

int maxProfit1(vector<int> &prices)
{ // O(N) , O(N)approch
    int maxProfit = 0;
    int n = prices.size();

    int arr[n];

    arr[n - 1] = prices[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        arr[i] = max(arr[i + 1], prices[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] - prices[i]) > maxProfit)
        {
            maxProfit = (arr[i] - prices[i]);
        }
    }
    return maxProfit;
}

int maxProfit2(vector<int> &prices)
{ // O(N) , O(1)approch
    int maxProfit = 0;
    int minSo = prices[0];
    for(int i = 0; i < prices.size(); i++){ 
        minSo = min(minSo , prices[i]);
        int profit = prices[i] - minSo;
        maxProfit = max(maxProfit , profit);
    }

    return maxProfit;
}

int main()
{
    vector<int> price;

    int N;
    cout << "enter the size: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cout << "the value at index " << i << " is: ";
        cin >> x;

        price.push_back(x);
    }

    int ans = maxProfit1(price);
    cout << ans << endl;
    return 0;
}