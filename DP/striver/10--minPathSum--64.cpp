// leetcode 64
// Minimum Path Sum


// Space optimized tabulation - Bottomup approach
// Time O(n*m)
// Space O(n*m)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int prev[m];
        int curr[m];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(i==0 && j==0) curr[0] = grid[0][0];
                else if(i==0) curr[j] = grid[0][j] + curr[j-1];
                else if(j==0) curr[0] = grid[i][0] + prev[0];
                else curr[j] = grid[i][j] + min(curr[j-1], prev[j]);
            }
            for(int k=0; k<m; ++k) prev[k] = curr[k];
        }
        return curr[m-1];
    }
};


// Tabulation - Bottom up approach
// Time O(n*m)
// Space O(n*m)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else if(i==0) dp[i][j] = grid[0][j] + dp[0][j-1];
                else if(j==0) dp[i][j] = grid[i][0] + dp[i-1][0];
                else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};

// Memoization
// Time O(n*m)
// Space O(n*m) [Function call stack O(n+m) + array O(n*m)]
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = solve(n-1, m-1, grid, dp);
        return ans;
    }
};