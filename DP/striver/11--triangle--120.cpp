// Triangle
// leetcode 120

// Space optimized Tabulation - Bottom up approach
// Time O(n2)
// Space O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int curr[n];
        int prev[n];
        for(int i=0; i<n; ++i) {
            curr[i] = triangle[n-1][i];
            prev[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j+1];
                curr[j] = min(down, diagonal);
            }
            for(int k=0; k<=i; ++k) prev[k] = curr[k];
        }
        return curr[0];
    }
};

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


// Not a good approach
// Here we are travelling from top to bottom (to a particular index)
// And the call this function for every point in bottom cell
int solve(int index, int col, vector<vector<int>>& tri,  vector<vector<int>>& dp) {
    if(col<0 || (col>index)) return INT_MAX;
    if(index==0 && col==0) return tri[0][0];
    if(dp[index][col]!=-1) return dp[index][col];
    int left = solve(index - 1, col - 1, tri, dp);
    int right = solve(index - 1, col, tri, dp);
    return dp[index][col] = min(left, right) + tri[index][col];
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int ans = INT_MAX;
    for(int i=0; i<n; ++i) {
        vector<vector<int>> dp(n);
        for(int i=0; i<n; ++i) {
            dp[i] = vector<int> (i+1, -1);
        }
        ans = min(ans, solve(n-1, i, triangle, dp));
    }
    return ans;
}