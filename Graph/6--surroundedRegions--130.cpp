// Leetcode 130

class Solution {
public:
    
    void dfs(int r, int c, int row, int col, vector<vector<char>> &board) {
        if(r<0 || r>=row || c<0 || c>=col || board[r][c]!='O') return;
        board[r][c] = 'V';
        dfs(r, c+1, row, col, board);
        dfs(r, c-1, row, col, board);
        dfs(r+1, c, row, col, board);
        dfs(r-1, c, row, col, board);
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row==0) return;
        int col = board[0].size();
        
        for(int i=0; i<col; ++i) {
            if(board[0][i]=='O') {
                dfs(0, i, row, col, board);
            }
            if(board[row-1][i]=='O') {
                dfs(row-1, i, row, col, board);
            }
        }
        
        for(int i=1; i<row-1; ++i) {
            if(board[i][0]=='O') {
                dfs(i, 0, row, col, board);
            }
            if(board[i][col-1]=='O') {
                dfs(i, col-1, row, col, board);
            }
        }
        
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(board[r][c]=='V') {
                    board[r][c] = 'O';
                }
                else if(board[r][c]=='O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};