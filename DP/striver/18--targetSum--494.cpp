// leetcode 494
// Target Sum
// Partitions With Given Difference

// Memoization
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