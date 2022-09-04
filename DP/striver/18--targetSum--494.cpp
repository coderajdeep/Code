// leetcode 494
// Target Sum
// Partitions With Given Difference


// Tabulation - Bottom up approach
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; ++i) sum += nums[i];
        int tar = sum + target;
        if(tar<0 || tar%2==1) return 0;
        tar /= 2;
        int dp[n][tar+1];
        dp[0][0] = (nums[0]==0)?2:1;
        for(int i=1; i<=tar; ++i) dp[0][i] = (nums[0]==i)?1:0;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<=tar; ++j) {
                int take = 0;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                int notTake = dp[i-1][j];
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][tar];
    }
};

// Memoization - Top Down approach
class Solution {
public:
    int solve(int index, int tar, vector<int> &nums, vector<vector<int>> &dp) {
        if(index==0) {
            if(nums[0]==0 && tar==0) return 2;
            if(tar==0 || tar==nums[0]) return 1;
            return 0;
        }
        if(dp[index][tar]!=-1) return dp[index][tar];
        int take = 0;
        if(nums[index]<=tar) take = solve(index-1, tar-nums[index], nums, dp);
        int notTake = solve(index-1, tar, nums, dp);
        return dp[index][tar] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; ++i) sum += nums[i];
        int tar = sum + target;
        if(tar<0 || (tar%2==1)) return 0;
        tar /= 2;
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        int ans = solve(n-1, tar, nums, dp);
        return ans;
    }
};