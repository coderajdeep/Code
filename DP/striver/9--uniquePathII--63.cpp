// leetcode 63
// Unique paths II

// Space optimized Tabulation - Bottom up approach
// Time O(n*m)
// Space O(m)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int prev[m];
        int curr[m];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(obstacleGrid[i][j]==1) curr[j] = 0;
                else if(i==0 && j==0) curr[j] = 1;
                else {
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                int up = 0, left = 0;
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;
                else {
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

// Memoization - Top down approach
// Time O(n*m)
// Space O(n*m) [function call stack O(n+m) + array O(n*m)]
class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if(i>=0 && j>=0 && arr[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = solve(i, j-1, arr, dp);
        int up = solve(i-1, j, arr, dp);
        return dp[i][j] = left + up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = solve(n-1, m-1, obstacleGrid, dp);
        return ans;
    }
};