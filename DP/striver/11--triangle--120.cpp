// Triangle
// leetcode 120

// Tabulation - Bottom up approach
// Time O(n2)
// Space O(n2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        for(int i=0; i<n; ++i) dp[n-1][i] = triangle[n-1][i];
        for(int i=n-2; i>=0 ; --i) {
            for(int j=0; j<=i; ++j) {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};


// Memoization - Top down approach
// Time O(n2)
// Space O(n2) [Function call stack O(n) + array O(n2)]
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if(i==n-1) return arr[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = arr[i][j] + solve(i+1, j, n, arr, dp);
        int digonal = arr[i][j] + solve(i+1, j+1, n, arr, dp);
        return dp[i][j] = min(down, digonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int n = dp.size();
        for(int i=0; i<n; ++i) {
            int m = dp[i].size();
            for(int j=0; j<m; ++j) {
                dp[i][j] = -1;
            }
        }
        int ans = solve(0, 0, n, triangle, dp);
        return ans;
    }
};