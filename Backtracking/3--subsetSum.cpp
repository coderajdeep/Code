class Solution {
public:

    void solve(int index, int n, int sum, vector<int> &ans, vector<int> &arr) {
        if(index==n) {
            ans.push_back(sum);
            return;
        }
        solve(index+1, n, sum + arr[index], ans, arr);
        solve(index+1, n, sum, ans, arr);
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        if(n==0) return {};
        vector<int> ans;
        solve(0, n, 0, ans, arr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};