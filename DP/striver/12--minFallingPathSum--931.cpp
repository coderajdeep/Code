// Leetcode 931
// Minimum falling path sum

// Memoization
// Time O(n*m*m)
// Space O(n*m)
class Solution {
public:
    void init(int n, int m, vector<vector<int>> &dp) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                dp[i][j] = -1;
            }
        }
    }
    int solve(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = matrix[i][j] + solve(i-1, j, m, matrix, dp);
        int l = matrix[i][j] + solve(i-1, j-1, m, matrix, dp);
        int r = matrix[i][j] + solve(i-1, j+1, m, matrix, dp);
        return dp[i][j] = min({up, l, r});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp = matrix;
        int ans = INT_MAX;
        for(int i=0; i<m; ++i) {
            init(n, m, dp);
            ans = min(ans, solve(n-1, i, m, matrix, dp));
        }
        return ans;
    }
};