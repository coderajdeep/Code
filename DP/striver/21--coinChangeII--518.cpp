// Coin Change II
// Leetcode 518


// Sapce optimized
// Uisng 1D array
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount+1];
        dp[0] = 1;
        for(int i=1; i<=amount; ++i) dp[i] = (i%coins[0]==0)?1:0;
        for(int i=1; i<n; ++i) {
            for(int j=1; j<=amount; ++j) {
                int take = 0;
                if(coins[i]<=j) take = dp[j-coins[i]];
                int notTake = dp[j];
                dp[j] = take + notTake;
            }
        }
        return dp[amount];
    }
};


// Space optimized bottom up approach
// Tabulation
int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int prev[amount+1];
        int curr[amount+1];
        curr[0] = 1;
        for(int i=0; i<=amount; ++i) prev[i] = (i%coins[0]==0)?1:0;
        for(int i=1; i<n; ++i) {
            for(int j=1; j<=amount; ++j) {
                int take = 0;
                if(coins[i]<=j) take = curr[j-coins[i]];
                int notTake = prev[j];
                curr[j] = take + notTake;
            }
            for(int i=1; i<=amount; ++i) prev[i] = curr[i];
        }
        return prev[amount];
    }


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