// leetcode 39
// All the elements are distinct in given array
// One element can be used multiple times

class Solution {
public:
    
    void solve(int index, int n, int sum, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if(index==n) {
            if(sum==0) {
                ans.push_back(ds);
            }
            return;
        }
        
        if(arr[index]<=sum) {
            ds.push_back(arr[index]);
            solve(index, n, sum-arr[index], arr, ds, ans);
            ds.pop_back();
        }
        solve(index+1, n, sum, arr, ds, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return {};
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0, n, target, candidates, ds, ans);
        return ans;
    }
};