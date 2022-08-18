// Leetcode 931
// Minimum falling path sum


// tabulation - bottom up approach
// Time O(n*m)
// Space O(n*m)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(i==0) dp[i][j] = matrix[i][j];
                else {
                    int up = matrix[i][j] + dp[i-1][j];
                    int l = j>0 ? (matrix[i][j] + dp[i-1][j-1]) : INT_MAX;
                    int r = j<n-1 ? (matrix[i][j] + dp[i-1][j+1]) : INT_MAX;
                    dp[i][j] = min({up, l, r});
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<m; ++i) ans = min(ans, dp[n-1][i]);
        return ans;
    }
};

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