#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> umap;

    stack<int>st;

    int n = nums2.size();

    for(int i = n-1; i>=0; i--){
        int ele = nums2[i];
        while(!st.empty() && st.top() <= ele){
            st.pop();
        }
        int ans = (st.empty()) ? -1 : st.top();
        umap.insert({ele, ans});
        st.push(ele);
    }        

    vector<int> ans;
    for(auto i : nums1){
        ans.push_back(umap[i]);
    }

    return ans;
}