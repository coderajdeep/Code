// Tricky
// leetcode 90
// need to understand
// similar with combination sum II (leetcode 40)

class Solution {
public:
    
    void solve(int index, int n, vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp) {
        ans.push_back(temp);
        
        for(int i=index; i<n; ++i) {
            if(i>index and arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            solve(i+1, n, ans, arr, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, n, ans, nums, temp);
        
        return ans;
    }
};