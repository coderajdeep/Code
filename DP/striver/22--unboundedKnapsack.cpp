// Unbounded knapsack
// Geeks


// Sapce optimized
// Using only one 1D array
int knapSack(int N, int W, int val[], int wt[]) {
    int dp[W+1];
    for(int i=0; i<=W; ++i) dp[i] = (wt[0]<=i)?((i/wt[0])*val[0]):0;
    for(int i=1; i<N; ++i) {
        for(int j=1; j<=W; ++j) {
            int take = INT_MIN;
            if(wt[i]<=j) take = val[i] + dp[j-wt[i]];
            int notTake = dp[j];
            dp[j] = max(take, notTake);
        }
    }
    return dp[W];
}

// Space optimized
// Bottom up approach
// Tabulation
int knapSack(int N, int W, int val[], int wt[]) {
        int prev[W+1];
        int curr[W+1];
        prev[0] = curr[0] = 0;
        for(int i=1; i<=W; ++i) prev[i] = (wt[0]<=i)?((i/wt[0])*val[0]):0;
        for(int i=1; i<N; ++i) {
            for(int j=1; j<=W; ++j) {
                int take = 0;
                if(wt[i]<=j) take = val[i] + curr[j-wt[i]];
                int notTake = prev[j];
                curr[j] = max(take, notTake);
            }
            for(int i=0; i<=W; ++i) prev[i] = curr[i];
        }
        return prev[W];
    }


// Bottom up approach
// Tabulation
int knapSack(int n, int W, int val[], int wt[]) {
    int dp[n][W+1];
    for(int i=0; i<=W; ++i) dp[0][i] = (wt[0]<=i)?((i/wt[0])*val[0]):0;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=W; ++j) {
            int take = 0;
            if(wt[i]<=j) take = val[i] + dp[i][j-wt[i]];
            int notTake = dp[i-1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][W];
}

// Top down approach
// Memoization

int solve(int index, int W, int *wt, int *val, vector<vector<int>> &dp) {
    if(W==0) return 0;
    if(index==0) return (wt[0]<=W)?((W/wt[0])*val[0]):0;
    if(dp[index][W]!=-1) return dp[index][W];
    int take = 0;
    if(wt[index]<=W) take = val[index] + solve(index, W-wt[index], wt, val, dp);
    int notTake = solve(index-1, W, wt, val, dp);
    return dp[index][W] = max(take, notTake);
}
int knapSack(int N, int W, int val[], int wt[]) {
    vector<vector<int>> dp(N, vector<int>(W+1, -1));
    int ans = solve(N-1, W, wt, val, dp);
    return ans;
}