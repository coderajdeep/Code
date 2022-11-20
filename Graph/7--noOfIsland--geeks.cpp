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

// Geeksforgeeks
// Both dfs and bfs approach
void dfs(int r, int c, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &visited, vector<vector<int>> &dirs) {
    if(r<0 || r>=n || c<0 || c>=m || grid[r][c]!='1' || visited[r][c]) return;
    visited[r][c] = true;
    for(int i=0; i<8; ++i) {
        dfs(r+dirs[i][0], c+dirs[i][1], n, m, grid, visited, dirs);
    }
}

void bfs(int r, int c, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &visited, vector<vector<int>> &dirs) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i=0; i<8; ++i) {
            int a = p.first + dirs[i][0];
            int b = p.second + dirs[i][1];
            // both if condition will work
            // if(a<0 || a>=n || b<0 || b>=m || grid[a][b]!='1' || visited[a][b]) continue;
            if(a>=0 && a<n && b>=0 && b<m && grid[a][b]=='1' && !visited[a][b]) {
                q.push({a, b});
                visited[a][b] = true;
            }
        }
    }
}
    
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    int count = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(grid[i][j]=='1' && !visited[i][j]) {
                ++count;
                bfs(i, j, n, m, grid, visited, dirs);
            }
        }
    }
    return count;
}