// Leetcode 1463
// Cherry Pickup II

// Memoization
// Time O(n*m*m)
// Space O(n*m*m)

class Solution {
public:
    
    int solve(int row, int colOne, int colTwo, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(colOne<0 || colTwo<0 || colOne>=m || colTwo>=m) return -1e9;
        if(row==n-1 && colOne==colTwo) return grid[n-1][colOne];
        if(row==n-1) return grid[n-1][colOne] + grid[n-1][colTwo];
        if(dp[row][colOne][colTwo]!=-1) return dp[row][colOne][colTwo];
        int maxValue = INT_MIN;
        for(int i=-1; i<=1; ++i) {
            for(int j=-1; j<=1; ++j) {
                int value = solve(row+1, colOne+i, colTwo+j, n, m, grid, dp);
                value = colOne == colTwo ? (value + grid[row][colOne]) : (value + grid[row][colOne] + grid[row][colTwo]);
                maxValue = max(maxValue, value);
            }
        }
        return dp[row][colOne][colTwo] = maxValue;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        int ans = solve(0, 0, m-1, n, m, grid, dp);
        return ans;
    }
};