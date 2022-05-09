// space should be optimized

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        vector<vector<int>>temp(matrix.begin(), matrix.end());
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                matrix[i][j] = temp[n-1-j][i];
            }
        }
    }
};