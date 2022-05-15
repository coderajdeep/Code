// Leetcode 77

// Given n and k
// Need to return all possible combinations of k sized subsequence out of the range [1, n]

class Solution {
public:
    
    // This need to be optimized
    
    void solve(int index, int n, int k, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if(index==n) {
            if(ds.size()==k) {
                ans.push_back(ds);
            }
            return;
        }
        
        ds.push_back(arr[index]);
        solve(index+1, n, k, arr, ds, ans);
        ds.pop_back();
        solve(index+1, n, k, arr, ds, ans);
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(n==1) return {{1}};
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> arr(n);
        for(int i=0; i<n; ++i) {
            arr[i] = i+1;
        }
        solve(0, n, k, arr, ds, ans);
        return ans;
    }
};