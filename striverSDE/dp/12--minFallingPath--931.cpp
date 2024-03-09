// Minimum falling path in rectangle -- leetcode 931 (Variable starting and ending point)

// Space optimised
// Time complexity O(n*n)
// Space complexity O(n)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev(matrix[n-1].begin(), matrix[n-1].end()), curr(n);
    for(int i=n-2; i>=0; --i) {
        for(int j=0; j<n; ++j) {
            int left = (j>0) ? prev[j-1] : INT_MAX;
            int down = prev[j];
            int right = (j<n-1) ? prev[j+1] : INT_MAX;
            curr[j] = matrix[i][j] + min({left, down, right});
        }
        for(int j=0; j<n; ++j) {
            prev[j] = curr[j];
        }
    }
    int minValue = INT_MAX;
    for(int i=0; i<n; ++i) {
        minValue = min(minValue, prev[i]);
    }
    return minValue;
}

// Top down
// Memoization
// Time complexity O(n*n)
// Space complexity O(n*n) + recursion call stack O(n)
// We can start from top as well as bottom
// TLE in leetcode
int minPath(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if(j<0 || j==n) return INT_MAX;
    if(i+1==n) return matrix[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = minPath(i+1, j, n, matrix, dp);
    int right = minPath(i+1, j+1, n, matrix, dp);
    int left = minPath(i+1, j-1, n, matrix, dp);
    return dp[i][j] = matrix[i][j] + min({left, down, right});
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int minPathSum = INT_MAX;
    for(int i=0; i<n; ++i) {
        minPathSum = min(minPathSum, minPath(0, i, n, matrix, dp));
    }
    return minPathSum;
}

// Tabulation
// Time complexity O(n*n)
// Space complexity O(n*n)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i=n-1; i>=0; --i) {
        for(int j=0; j<n; ++j) {
            if(i==n-1) {
                dp[i][j] = matrix[i][j];
            }
            else {
                int left = (j>0) ? dp[i+1][j-1] : INT_MAX;
                int down = dp[i+1][j];
                int right = (j<n-1) ? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({left, down, right});
            }
        }
    }
    int minValue = INT_MAX;
    for(int i=0; i<n; ++i) {
        minValue = min(minValue, dp[0][i]);
    }
    return minValue;
}