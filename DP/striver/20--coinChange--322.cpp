// leetcode 322
// Coin change

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