// leetcode 37

bool isValid(int row, int col, char ch, vector<vector<char>> &board) {
        for(int i=0; i<9; ++i) {
            if(board[i][col]==ch) return false;
            else if(board[row][i]==ch) return false;
            else if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==ch) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board) {
        for(int row=0; row<board.size(); ++row) {
            for(int col=0; col<board[0].size(); ++col) {
                if(board[row][col]=='.') {
                    for(char ch='1'; ch<='9'; ++ch) {
                        if(isValid(row, col, ch, board)) {
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }