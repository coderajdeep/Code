// Unbounded knapsack

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