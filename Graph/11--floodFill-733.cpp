// Flood fill 
// leetcode 733
// BFS and DFS approach

class Solution {
public:

    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isValid(int r, int c, int row, int col) {
        if(r<0 || r>=row || c<0 || c>=col) return false;
        return true;
    }

    void dfs(int r, int c, int row, int col, int color, int initColor, vector<vector<int>> &ans) {
        ans[r][c] = color;
        for(int i=0; i<4; ++i) {
            int x = r + dirs[i][0];
            int y = c + dirs[i][1];
            if(isValid(x, y, row, col) && ans[x][y]==initColor) {
                dfs(x, y, row, col, color, initColor, ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int initColor = image[sr][sc];
        vector<vector<int>> ans(image.begin(), image.end());
        if(initColor!=color) dfs(sr, sc, row, col, color, initColor, ans);
        return ans;
    }
};


// Flood fill 
// leetcode 733
// BFS and DFS approach

class Solution {
public:
    
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(int r, int c, int n, int m, int old, int color, vector<vector<bool>> &visited, vector<vector<int>> &image) {
        if(r<0 || r>=n || c<0 || c>=m || visited[r][c] || image[r][c]!=old) return;
        image[r][c] = color;
        visited[r][c] = true;
        for(int i=0; i<4; ++i) {
            dfs(r+dirs[i][0], c+dirs[i][1], n, m, old, color, visited, image);
        }
    }
    
    void bfs(int r, int c, int n, int m, int old, int color, vector<vector<bool>> &visited, vector<vector<int>> &image) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        image[r][c] = color;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int a = p.first + dirs[i][0];
                int b = p.second + dirs[i][1];
                if(a>=0 && a<n && b>=0 && b<m && !visited[a][b] && image[a][b]==old) {
                    q.push({a, b});
                    visited[a][b] = true;
                    image[a][b] = color;
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int old = image[sr][sc];
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bfs(sr, sc, n, m, old, color, visited, image);
        return image;
    }
};


// without using new matrix
// geeks
// bfs and dfs
class Solution{
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool isValid(int r, int c, int row, int col) {
        if(r<0 || r>=row || c<0 || c>=col) return false;
        return true;
    }
    void dfs(int r, int c, int row, int col, int color, int newColor, vector<vector<int>> &image) {
        if(!isValid(r, c, row, col) || image[r][c]!=color) return;
        image[r][c] = newColor;
        for(int i=0; i<4; ++i) dfs(r+dirs[i][0], c+dirs[i][1], row, col, color, newColor, image);
    }
    void bfs(int r, int c, int row, int col, int color, int newColor, vector<vector<int>> &image) {
        queue<pair<int, int>> q;
        q.push({r, c});
        image[r][c] = newColor;
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int a = p.first + dirs[i][0];
                int b = p.second + dirs[i][1];
                if(isValid(a, b, row, col) && image[a][b]==color) {
                    q.push({a, b});
                    image[a][b] = newColor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        int color = image[sr][sc];
        if(color!=newColor) bfs(sr, sc, row, col, color, newColor, image);
        return image;
    }
};