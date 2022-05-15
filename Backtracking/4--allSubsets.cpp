// leetcode 78
// We need to generate all the subsequence/subset

class Solution {
public:
    
    void solve(int index, int n, vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[index]);
        solve(index+1, n, ans, arr, temp);
        temp.pop_back();
        solve(index+1, n, ans, arr, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, n, ans, nums, temp);
        
        return ans;
    }
};


// Another solution

class Solution {
public:
    
    void solve(int index, int n, vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        solve(index+1, n, ans, arr, temp);
        temp.push_back(arr[index]);
        solve(index+1, n, ans, arr, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, n, ans, nums, temp);
        
        return ans;
    }
};