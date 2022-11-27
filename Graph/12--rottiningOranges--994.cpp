// Rottining Oranges
// leetcode 994

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