// Coin Change II
// Leetcode 518


// Bottom up approach
// Tabulation
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[n][amount+1];
    for(int i=0; i<=amount; ++i) dp[0][i] = (i%coins[0]==0)?1:0;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=amount; ++j) {
            int take = 0;
            if(coins[i]<=j) take = dp[i][j-coins[i]];
            int notTake = dp[i-1][j];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n-1][amount];
}


// Top Down Approach
// Memoization
int solve(int index, int tar, vector<int> &coins, vector<vector<int>> &dp) {
    if(tar==0) return 1;
    if(index==0) return (tar%coins[0]==0)?1:0;
    if(dp[index][tar]!=-1) return dp[index][tar];
    int take = 0;
    if(coins[index]<=tar) take = solve(index, tar-coins[index], coins, dp);
    int notTake = solve(index-1, tar, coins, dp);
    return dp[index][tar] = take + notTake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int ans = solve(n-1, amount, coins, dp);
    return ans;
}