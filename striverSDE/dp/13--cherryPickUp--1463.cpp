// Cherry Pickup II -- leetcode 1463

// Time complexity O(row*col*col)
// Space complexity O(row*col*col)
int getMaxCherry(int x, int y1, int y2, int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if(y1<0 || y1>=col || y2<0 || y2>=col) {
        return INT_MIN;
    }
    if(x == row-1) {
        if(y1 == y2) {
            return grid[x][y1];
        }
        else {
            return (grid[x][y1] + grid[x][y2]);
        }
    }

    if(dp[x][y1][y2] != -1) return dp[x][y1][y2];

    long maxValue = INT_MIN;

    for(int d1=-1; d1<=1; ++d1) {
        for(int d2=-1; d2<=1; ++d2) {
            if(y1 == y2) {
                long val = grid[x][y1] + getMaxCherry(x+1, y1+d1, y2+d2, row, col, grid, dp);
                maxValue = max(maxValue, val);
            }
            else {
                long val = grid[x][y1] + grid[x][y2] + getMaxCherry(x+1, y1+d1, y2+d2, row, col, grid, dp);
                maxValue = max(maxValue, val);
            }
        }
    }

    return dp[x][y1][y2] = maxValue;
}
int cherryPickup(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
    return getMaxCherry(0, 0, col-1, row, col, grid, dp);
}