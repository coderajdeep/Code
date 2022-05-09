// leetcode 39
// All the elements are distinct in given array
// One element can 

class Solution {
public:
    void solve(int index, int target, int n, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr) {
        if(index==n) {
            if(target==0) {
                ans.push_back(temp);
            }
            return;
        }
        if(arr[index]<=target) {
            temp.push_back(arr[index]);
            solve(index, target - arr[index], n, temp, ans, arr);
            temp.pop_back();
        }
        // if we enclose this in else condition then it will not work
        solve(index+1, target, n, temp, ans, arr); 

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, n, temp, ans, candidates);
        return ans;
    }
};