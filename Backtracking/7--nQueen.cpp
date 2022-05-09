// leetcode 51

// Print all possible ways queen can be placed without attacking each other
// Will optimize the isSafe method

class Solution {
public:
    
    bool isSafe(int row, int col, int n, vector<string> &board) {
        int r = row, c = col;
        while(r>=0 and c>=0) {
            if(board[r--][c--]=='Q') return false;
        }
        r = row, c = col;
        while(c>=0) {
            if(board[r][c--]=='Q') return false;
        }
        c = col;
        while(r<n and c>=0) {
            if(board[r++][c--]=='Q') return false;
        }
        return true;
    }
    
    void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; ++row) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col+1, n, ans, board);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {};
        
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        
        solve(0, n, ans, board);
        
        return ans;
    }
};