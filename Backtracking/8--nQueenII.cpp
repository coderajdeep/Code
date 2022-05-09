// leetcode 52

// Find number of ways queen can be placed without attacking each other

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

    
    void solve(int col, int n, int &ans, vector<string> &board) {
        if(col==n) {
            ++ans;
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
    
    int totalNQueens(int n) {
        if(n==0) return 0;
        
        vector<string> board(n, string(n, '.'));
        int ans = 0;
        
        solve(0, n, ans, board);
        
        return ans;
    }
};