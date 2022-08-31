// Count subsets sum equals to K
// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532


// Space optimized tabulation
int findWays(vector<int> &num, int tar) {
    int n = num.size();
    int prev[tar+1];
    int curr[tar+1];
    prev[0] = 1;
    for(int i=1; i<=tar; ++i) prev[i] = (i==num[0])?1:0;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=tar; ++j) {
            int take = 0;
            if(num[i]<=j) take = prev[j-num[i]];
            int notTake = prev[j];
            curr[j] = take + notTake;
        }
        for(int k=1; k<=tar; ++k) prev[k] = curr[k];
    }
    return prev[tar];
}

// Tabulation
int findWays(vector<int> &num, int tar) {
    int n = num.size();
    int dp[n][tar+1];
    dp[0][0] = 1;
    for(int i=1; i<=tar; ++i) dp[0][i] = (num[0]==i)?1:0;
    for(int i=1; i<n; ++i) {
        dp[i][0] = 1;
        for(int j=1; j<=tar; ++j) {
            int take = 0;
            if(num[i]<=j) take = dp[i-1][j-num[i]];
            int notTake = dp[i-1][j];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n-1][tar];
}

// Memoization
int solve(int index, int tar, vector<int> &nums, vector<vector<int>> &dp) {
    if(tar==0) return 1;
    if(index==0) return (nums[0]==tar)?1:0;
    if(dp[index][tar]!=-1) return dp[index][tar];
    int take = 0;
    if(nums[index]<=tar) take = solve(index-1, tar-nums[index], nums, dp);
    int notTake = solve(index-1, tar, nums, dp);
    return dp[index][tar] = take + notTake;
}

int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    int ans = solve(n-1, tar, num, dp);
    return ans;
}