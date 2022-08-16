// Unique Paths
// leetcode 62
// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470


// Space optimized tabulation - Bottom up approach
// Space O(n) -- O(size of column)
// Time O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        vector<int>dp(n, 1);
        vector<int>curr(n);
        curr[0] = 1;
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                curr[j] = curr[j-1] + dp[j];
            }
            // dp = curr;
            for(int i=0; i<n; ++i) dp[i] = curr[i];
        }
        return dp[n-1];
    }
};

// Tabulation - Bottom up approach
// Time O(m*n)
// Space O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; ++i) dp[i][0] = 1;
        for(int i=0; i<n; ++i) dp[0][i] = 1;
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Memoization - Top down approach
// Time O(m*n)
// Space O(m*n) [O(m*n) -> Function call stack + O(m*n) -> array]
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp) {
        if(m==0 || n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up = solve(m-1, n, dp);
        int left = solve(m, n-1, dp);
        return dp[m][n] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = solve(m-1, n-1, dp);
        return ans;
    }
};


