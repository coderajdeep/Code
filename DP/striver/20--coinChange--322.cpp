// leetcode 322
// Coin change

// Important point
// We can not decide anything when target = 0
// test case : [1, 2] , target = 2


// Space optimized - Bottom up approach - Tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int curr[amount+1];
    int prev[amount+1];
    curr[0] = 1e9;
    
    for(int i=0; i<=amount; ++i) prev[i] = (i%coins[0]==0)?(i/coins[0]):1e9;
    
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=amount; ++j) {
            int take = 1e9;
            if(coins[i]<=j) take = 1 + curr[j-coins[i]];
            int notTake = prev[j];
            curr[j] = min(take, notTake);
        }
        for(int i=0; i<=amount; ++i) prev[i] = curr[i];
    }
    return (prev[amount]!=1e9)?prev[amount]:-1;
}


// Bottom up approach - Tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n][amount+1];
    for(int i=0; i<=amount; ++i) dp[0][i] = (i%coins[0]==0)?(i/coins[0]):1e9;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=amount; ++j) {
            int take = 1e9;
            if(coins[i]<=j) take = 1 + dp[i][j-coins[i]];
            int notTake = dp[i-1][j];
            dp[i][j] = min(take, notTake);
        }
    }
    return dp[n-1][amount]!=1e9?dp[n-1][amount]:-1;
}

// Top down approach - Memoization
int solve(int index, int tar, vector<int> &coins, vector<vector<int>> &dp) {
    if(index==0) return (tar%coins[0]==0)?(tar/coins[0]):1e9;
    if(dp[index][tar]!=-1) return dp[index][tar];
    int take = 1e9;
    if(coins[index]<=tar) take = 1 + solve(index, tar-coins[index], coins, dp);
    int notTake = solve(index-1, tar, coins, dp);
    return dp[index][tar] = min(take, notTake);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int ans = solve(n-1, amount, coins, dp);
    return ((ans==1e9)?-1:ans);
}