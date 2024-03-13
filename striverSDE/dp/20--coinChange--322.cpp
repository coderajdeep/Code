// Coin Change -- leetcode 322
// Memoization
// Time complexity O(n*amount)
// Space complexity O(n*amount)
long getMinCoin(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {
    if(index==0) {
        if(amount%coins[0] == 0) return (amount/coins[0]);
        else return INT_MAX;
    }
    if(dp[index][amount] != -1) return dp[index][amount];
    long pick = INT_MAX;
    if(coins[index]<=amount) pick = 1 + getMinCoin(index, amount-coins[index], coins, dp);
    long notPick = getMinCoin(index-1, amount, coins, dp);
    return dp[index][amount] = min(pick, notPick);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int ans = getMinCoin(n-1, amount, coins, dp);
    return (ans==INT_MAX) ? -1 : ans;
}

// Tabulation
// Time complexity O(n*amount)
// Space complexity O(n*amount)
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    long dp[n][amount+1];
    for(int i=0; i<=amount; ++i) {
        if(i % coins[0] == 0) dp[0][i] = (i / coins[0]);
        else dp[0][i] = INT_MAX;
    }
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=amount; ++j) {
            long pick = (coins[i]<=j) ? 1 + dp[i][j-coins[i]] : INT_MAX;
            long notPick = dp[i-1][j];
            dp[i][j] = min(pick, notPick);
        }
    }
    return dp[n-1][amount] != INT_MAX ? dp[n-1][amount] : -1;
}

// Space optimized
// Time complexity O(n*amount)
// Space complexity O(amount)
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    long prev[amount+1];
    long curr[amount+1];
    for(int i=0; i<=amount; ++i) {
        if(i % coins[0] == 0) prev[i] = (i / coins[0]);
        else prev[i] = INT_MAX;
    }
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=amount; ++j) {
            long pick = (coins[i]<=j) ? 1 + curr[j-coins[i]] : INT_MAX;
            long notPick = prev[j];
            curr[j] = min(pick, notPick);
        }
        for(int j=0; j<=amount; ++j) prev[j] = curr[j];
    }
    return prev[amount] != INT_MAX ? prev[amount] : -1;
}