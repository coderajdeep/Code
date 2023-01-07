// Rottining Oranges
// leetcode 994

// Updated solution
class Solution {
public:

    bool isValid(int r, int c, int row, int col) {
        if(r<0 || r>=row || c<0 || c>=col) return false;
        return true;
    }

    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // 2D vector for storing time to reach in each cell
        vector<vector<int>> time(row, vector<int>(col));
        // storing all the cells having rotten oranges in queue for bfs
        queue<pair<int, int>> q;

        for(int i=0; i<row; ++i) {
            for(int j=0; j<col; ++j) {
                if(grid[i][j]==0) time[i][j] = -1;
                else if(grid[i][j]==1) time[i][j] = 1e9;
                else {
                    time[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            pair<int, int> p = q.front();
            int a = p.first;
            int b = p.second;
            q.pop();
            for(int i=0; i<4; ++i) {
                int x = a + dirs[i][0];
                int y = b + dirs[i][1];
                if(isValid(x, y, row, col) && grid[x][y]==1 && (time[a][b]+1<time[x][y])) {
                    time[x][y] = time[a][b] + 1;
                    q.push({x, y});
                    grid[x][y] = 2;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<row; ++i) {
            for(int j=0; j<col; ++j) {
                if(time[i][j]==1e9) return -1;
                else ans = max(ans, time[i][j]);
            }
        }
        return ans;
    }
};

// Using multipoint bfs
class Solution {
public:
    
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &time, vector<pair<int, int>> &sources) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        for(pair<int, int>p:sources) q.push(p);
        int level = 1;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int, int> p = q.front();
                q.pop();
                for(int i=0;i<4; ++i) {
                    int a = p.first + dirs[i][0];
                    int b = p.second + dirs[i][1];
                    if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==1) {
                        grid[a][b] = 2;
                        q.push({a, b});
                        time[a][b] = level;
                    }
                }
            }
            ++level;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m));
        vector<pair<int, int>> sources;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==0) time[i][j] = -1;
                else if(grid[i][j]==1) time[i][j] = 1e9;
                else {
                    sources.push_back({i, j});
                    time[i][j] = 0;
                }
            }
        }
        bfs(grid, time, sources);
        int ans = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(time[i][j]==1e9) return -1;
                ans = max(ans, time[i][j]);
            }
        }
        return ans;
    }
};