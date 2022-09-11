// Coin Change II
// Leetcode 518

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