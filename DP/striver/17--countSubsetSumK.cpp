// Count subsets sum equals to K
// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

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