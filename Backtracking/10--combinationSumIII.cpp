// Leetcode 216

class Solution {
public:
    
    // This need to be optimized
    
    void solve(int index, int k, int n, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if(index==9) {
            if(ds.size()==k && n==0) {
                ans.push_back(ds);
            }
            return;
        }
        
        ds.push_back(arr[index]);
        solve(index+1, k, n-arr[index], arr, ds, ans);
        ds.pop_back();
        solve(index+1, k, n, arr, ds, ans);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        // Try to solve this without using this array
        vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
        solve(0, k, n, arr, ds, ans);
        return ans;
    }
};