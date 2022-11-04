
// leetcode 323
// Number of Connected Components in an Undirected Graph 
// https://leetcode.ca/2016-10-18-323-Number-of-Connected-Components-in-an-Undirected-Graph/



// // leetcode - 200


// class Solution {
// public:
    
//     void dfs(vector<vector<char>> &arr, int n, int m, int i, int j) {
//         if(i<0 or i>=n or j<0 or j>=m or arr[i][j]!='1') {
//             return;
//         }
        
//         arr[i][j] = '2';
        
//         dfs(arr, n, m, i-1, j); // up
//         dfs(arr, n, m, i+1, j); // down
//         dfs(arr, n, m, i, j-1); // left
//         dfs(arr, n, m, i, j+1); // right
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         if(n==0) {
//             return 0;
//         }
//         int m = grid[0].size();
        
//         int count = 0;
        
//         for(int i=0; i<n; ++i) {
//             for(int j=0; j<m; ++j) {
//                 if(grid[i][j]=='1') {
//                     ++count;
//                     dfs(grid, n, m, i, j);
//                 }
//             }
//         }
//         return count;
//     }
// };