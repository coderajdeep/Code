// leetcode 200

// TODO
// Number of island II
// leetcode 305

// here i have edited the given matrix
// if the given matrix is constant than we can  make our own visited array

// DFS approach
class Solution {
public:
    
    void dfs(int r, int c, int row, int col, vector<vector<char>> &grid) {
        // if the cell is not valid or not equals to '1' then will stop dfs
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

// DFS Approach
// Here I'm not editing the given grid
// I'm using an extra visted array
class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || grid[i][j]=='0') return;
        visited[i][j] = true;
        dfs(grid, visited, i+1, j, n, m);
        dfs(grid, visited, i-1, j, n, m);
        dfs(grid, visited, i, j+1, n, m);
        dfs(grid, visited, i, j-1, n, m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int ans = 0;
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    ++ans;
                    dfs(grid, visited, i, j, n, m);
                }
            }
        }
        return ans;
    }
};


// BFS Approach
// Create a different DFS function
class Solution {
public:
    
    void bfs(int r, int c, int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        
        while(!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int a = u.first + dirs[i][0];
                int b = u.second + dirs[i][1];
                if(a>=0 && a<row && b>=0 && b<col && !visited[a][b] && grid[a][b]=='1') {
                    q.push({a, b});
                    visited[a][b] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0) return 0;
        int col = grid[0].size();
        
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        
        int ans = 0;
        
        for(int i=0; i<row; ++i) {
            for(int j=0; j<col; ++j) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    ++ans;
                    bfs(i, j, row, col, grid, visited);
                }
            }
        }
        return ans;
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