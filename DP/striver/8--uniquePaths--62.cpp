// Unique Paths
// leetcode 62
// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

// leetcode 62
// Time O(m*n)
// Space O(2*n) ~ 2 * size of column
int uniquePaths(int m, int n) {
    if(m==1 || n==1) return 1;
    int prev[n], curr[n];
    for(int i=0; i<n; ++i) prev[i] = 1;
    for(int i=1; i<m; ++i) {
        curr[0] = 1;
        for(int j=1; j<n; ++j) {
            curr[j] = curr[j-1] + prev[j];
        }
        for(int k=1; k<n; ++k) prev[k] = curr[k];
    }
    return curr[n-1];
}

// Striver
// Space optimized tabulation - Bottom up approach
// Space O(n) -- O(size of column)
// Time O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        int curr[n];
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(i==0 && j==0) {
                    curr[0] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i>0) up = dp[j];
                if(j>0) left = curr[j-1];
                curr[j] = up + left;
            }
            for(int k=0; k<n; ++k) dp[k] = curr[k];
        }
        return dp[n-1];
    }
};


// Striver
// Tabulation - Bottom up approach
// Time O(m*n)
// Space O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int up = 0, left = 0;
                if(i==0 && j==0) {
                    dp[0][0] = 1;
                    continue;
                }
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};


// Memoization - Top down approach
// Time O(m*n)
// Space O(m*n) [O(path length) ~ O((m-1)+(n-1)) -> Function call stack + O(m*n) -> array]
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp) {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1, j, dp);
        int left = solve(i, j-1, dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = solve(m-1, n-1, dp);
        return ans;
    }
};


// Space optimized tabulation - Bottom up approach
// Space O(n) -- O(size of column)
// Time O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        int dp[n];
        int curr[n];
        for(int i=0; i<n; ++i) dp[i] = 1;
        curr[0] = 1;
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                curr[j] = curr[j-1] + dp[j];
            }
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
// Space O(m*n) [O(path length) ~ O((m-1)+(n-1)) -> Function call stack + O(m*n) -> array]
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


