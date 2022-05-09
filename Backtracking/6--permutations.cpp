// leetcode 46
// print all permutation of an array/string

// not using extra temp array

class Solution {
public:
    
    void solve(int index, int n, vector<vector<int>> &ans, vector<int> &arr) {
        if(index==n) {
            ans.push_back(arr);
            return;
        }
        
        for(int i=index; i<n; ++i) {
            swap(arr[index], arr[i]);
            solve(index+1, n, ans, arr);
            swap(arr[index], arr[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        
        vector<vector<int>> ans;
        
        solve(0, n, ans, nums);
        
        return ans;
    }
};



// using extra temp array

class Solution {
public:
    
    void solve(int n, vector<vector<int>> &ans, vector<int> &arr, vector<bool> &freq, vector<int> &ds) {
        if(n==ds.size()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; ++i) {
            if(freq[i]==false) {
                ds.push_back(arr[i]);
                freq[i] = true;
                solve(n, ans, arr, freq, ds);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(n, false);
        
        solve(n, ans, nums, freq, ds);
        
        return ans;
    }
};