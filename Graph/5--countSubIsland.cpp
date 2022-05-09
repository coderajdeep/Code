// leetcode 1905

class Solution {
public:
    
    void dfs(int r, int c, int row, int col, bool &flag, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(r<0 || r>=row || c<0 || c>=col || grid2[r][c]!=1) return;
        grid2[r][c] = 2;
        if(grid1[r][c]!=1) flag = false;
        dfs(r, c+1, row, col, flag, grid1, grid2);
        dfs(r, c-1, row, col, flag, grid1, grid2);
        dfs(r+1, c, row, col, flag, grid1, grid2);
        dfs(r-1, c, row, col, flag, grid1, grid2);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid1.size();
        if(row==0) return 0;
        int col = grid1[0].size();
        int count = 0;
        
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(grid2[r][c]==1) {
                    bool flag = true;
                    dfs(r, c, row, col, flag, grid1, grid2);
                    if(flag) ++count;
                }
                
            }
        } 
        return count;
    }
};