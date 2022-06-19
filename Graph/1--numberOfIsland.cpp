// leetcode 200
// here i have edited the given matrix
// if the given matrix is constant than we can  make our own visited array

// DFS approach
class Solution {
public:
    
    void dfs(int r, int c, int row, int col, vector<vector<char>> &grid) {
        // if the cell is not valid or not equals to '1' then will stup dfs
        if(r<0 or r>=row or c<0 or c>=col or grid[r][c]!='1') return;
        grid[r][c] = '2';
        
        dfs(r, c+1, row, col, grid); // move right
        dfs(r, c-1, row, col, grid); // move left
        dfs(r+1, c, row, col, grid); // move down
        dfs(r-1, c, row, col, grid); // move up
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0) return 0;
        int col = grid[0].size();
        int count = 0;
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(grid[r][c]=='1') {
                    ++count;
                    dfs(r, c, row, col, grid);
                }
            }
        }
        return count;
    }
};


// BFS Approach
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0) return 0;
        int col = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(grid[r][c]=='1') {
                    ++ans;
                    q.push({r, c});
                    while(!q.empty()) {
                        auto x = q.front();
                        q.pop();
                        int u = x.first;
                        int v = x.second;
                        if(grid[u][v]=='1') {
                            grid[u][v] = '2';
                            for(auto dir:dirs) {
                                int a = u + dir[0];
                                int b = v + dir[1];
                                if(a>=0 && a<row && b>=0 && b<col) {
                                    q.push({a, b});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};