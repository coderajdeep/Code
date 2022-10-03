// No of island
// Eight directional 

void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<int>> &dirs) {
    if(i>=n || i<0 || j>=m || j<0 || visited[i][j] || grid[i][j]=='0') return;
    visited[i][j] = true;
    for(int in=0; in<8; ++in) dfs(i+dirs[in][0], j+dirs[in][1], n, m, grid, visited, dirs);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // right, left, down, up, up left digonal, down right diagonal, down left diagonal, up right diagonal
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
    int count = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(grid[i][j]=='1' && !visited[i][j]) {
                ++count;
                dfs(i, j, n, m, grid, visited, dirs);
            }
        }
    }
    return count;
}