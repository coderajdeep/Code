// Leetcode 73

class Solution {
public:
    
    // Time complexity O(n*m)
    // Space complexity O(n+m)
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size(); // no of rows
        int m = matrix[0].size(); // no of columns
        
        vector<bool>row(n, false), column(m, false);
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(matrix[i][j]==0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(row[i]==true or column[j]==true) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



// We can make it more simplified

class Solution {
public:

    // Time complexity O(n*m)
    // Space complexity O(1)

    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firstRow = false;
        
        for(int i=0; i<m; ++i) {
            if(matrix[0][i]==0) {
                firstRow = true;
                break;
            }
        }
        
        for(int i=1; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                if(matrix[i][0]==0 or matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0]==0) {
            for(int i=0; i<n; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        if(firstRow) {
            for(int i=0; i<m; ++i) {
                matrix[0][i] = 0;
            }
        }
        
    }
};