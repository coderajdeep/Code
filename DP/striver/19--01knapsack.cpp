// Geeks
// Coding Ninja


// Space optimized - Used only one 1D array - Tabulation - Bottom up
int knapSack(int W, int wt[], int val[], int n) { 
    int dp[W+1];
    for(int i=0; i<=W; ++i) dp[i] = (wt[0]<=i)?val[0]:0;
    for(int i=1; i<n; ++i) {
        for(int j=W; j>=0; --j) {
            int take = 0;
            if(wt[i]<=j) take = val[i] + dp[j-wt[i]];
            int notTake = dp[j];
            dp[j] = max(take, notTake);
        }
    }
    return dp[W];
}


// Space optimized tabulation
int knapSack(int W, int wt[], int val[], int n) { 
    int prev[W+1];
    int curr[W+1];
    for(int i=0; i<=W; ++i) prev[i] = (wt[0]<=i)?val[0]:0;
    for(int i=1;i<n; ++i) {
        for(int j=0; j<=W; ++j) {
            int take = 0;
            if(wt[i]<=j) take = val[i] + prev[j-wt[i]];
            int notTake = prev[j];
            curr[j] = max(take, notTake);
        }
        for(int i=0; i<=W; ++i) prev[i] = curr[i];
    }
    return prev[W];
}


// Bottom up approach - tabulation
int knapSack(int W, int wt[], int val[], int n) { 
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