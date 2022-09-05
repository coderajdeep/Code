// Geeks
// Coding Ninja


// Bottom up approach - tabulation
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int dp[n][W+1];
    for(int i=0; i<=W; ++i) dp[0][i] = (wt[0]<=i)?val[0]:0;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=W; ++j) {
            int pick = 0;
            if(wt[i]<=j) pick = val[i] + dp[i-1][j-wt[i]];
            int notPick = dp[i-1][j];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n-1][W];
}

// Top down approach
// Memoization
int solve(int index, int W, int *wt, int *val, vector<vector<int>> &dp) {
    if(W==0) return 0;
    if(index==0) {
        if(wt[0]<=W) return val[0];
        return 0;
    }
    if(dp[index][W]!=-1) return dp[index][W];
    int pick = 0;
    if(wt[index]<=W) pick = val[index] + solve(index-1, W-wt[index], wt, val, dp);
    int notPick = solve(index-1, W, wt, val, dp);
    return dp[index][W] = max(pick, notPick);
}
int knapSack(int W, int wt[], int val[], int n) { 
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    int ans = solve(n-1, W, wt, val, dp);
    return ans;
}