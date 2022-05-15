// Tricky
// leetcode 40
// https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

class Solution {
public:
    
    void solve(int index, int n, int target, vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp) {
        
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index; i<n; ++i) {
            if(i>index and arr[i]==arr[i-1]) continue;
            else if(arr[i]>target) break;
            temp.push_back(arr[i]);
            solve(i+1, n, target-arr[i], ans, arr, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return {};
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, n, target, ans, candidates, temp);
        
        return ans;
    }
};