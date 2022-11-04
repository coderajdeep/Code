// leetcode 695
// Need to find max area among the disconnected components of graph/matrix

class Solution {
public:
    
    void dfs(int r, int c, int row, int col, int &area, vector<vector<int>> &grid) {
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]!=1) return;
        ++area;
        grid[r][c] = 2;
        
        dfs(r, c+1, row, col, area, grid);
        dfs(r, c-1, row, col, area, grid);
        dfs(r-1, c, row, col, area, grid);
        dfs(r+1, c, row, col, area, grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row==0) return 0;
        int col = grid[0].size();
        int ans = 0, area;
        
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(grid[r][c]==1) {
                    area = 0;
                    dfs(r, c, row, col, area, grid);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};