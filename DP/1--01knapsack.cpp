// bottom up approach -- tabualation

class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(W==0 || n==0) {
           return 0;
       }
       
       int dp[n+1][W+1];
       
       for(int i=0; i<=n; ++i) {
           dp[i][0] = 0;
       }
       
       for(int i=0; i<=W; ++i) {
           dp[0][i] = 0;
       }
       
       for(int i=1; i<=n; ++i) {
           for(int j=1; j<=W; ++j) {
               if(wt[i-1]>j) {
                   dp[i][j] = dp[i-1][j];
               }
               else {
                   dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
               }
           }
       }
       return dp[n][W];
    }
};



// top down approah -- memoization 

class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapsack(int W, int wt[], int val[], int n, vector<vector<int>> &dp) {
        if(W==0 or n==0) {
            return 0;
        }
        if(dp[n][W]!=-1) {
            return dp[n][W];
        }
        if(W<wt[n-1]) {
            return dp[n][W] = knapsack(W, wt, val, n-1, dp);
        }
        return dp[n][W] = max(knapsack(W, wt, val, n-1, dp), val[n-1] + knapsack(W-wt[n-1], wt, val, n-1, dp));
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(W==0 or n==0) {
            return 0;
        }
        vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
        
        return knapsack(W, wt, val, n, dp);
    }
};