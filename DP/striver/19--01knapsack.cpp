// Geeks
// Coding Ninja

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