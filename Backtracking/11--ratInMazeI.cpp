// Geeksforgeeks
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    
    void solve(int r, int c, int n, vector<string> &ans, string &path, vector<vector<int>> &mat, vector<vector<bool>> &vis) {
        if(r==n-1 && c==n-1) {
            ans.push_back(path);
            return;
        }
        
        // Down
        if(r+1<n && !vis[r+1][c] && mat[r+1][c]) {
            vis[r][c] = true;
            path.push_back('D');
            solve(r+1, c, n, ans, path, mat, vis);
            path.pop_back();
            vis[r][c] = false;
        }
        
        // Left
        if(c-1>=0 && !vis[r][c-1] && mat[r][c-1]) {
            vis[r][c] = true;
            path.push_back('L');
            solve(r, c-1, n, ans, path, mat, vis);
            path.pop_back();
            vis[r][c] = false;
        }
        
        // Right
        if(c+1<n && !vis[r][c+1] && mat[r][c+1]) {
            vis[r][c] = true;
            path.push_back('R');
            solve(r, c+1, n, ans, path, mat, vis);
            path.pop_back();
            vis[r][c] = false;
        }
        
        // Up
        if(r-1>=0 && !vis[r-1][c] && mat[r-1][c]) {
            vis[r][c] = true;
            path.push_back('U');
            solve(r-1, c, n, ans, path, mat, vis);
            path.pop_back();
            vis[r][c] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(n==0) return {};
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<string> ans;
        string path;
        if(m[0][0]==1) {
            solve(0, 0, n, ans, path, m, vis);
        }
        return ans;
    }
};
