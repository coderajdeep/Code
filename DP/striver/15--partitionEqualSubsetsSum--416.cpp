// Leetcode 416
// Partition equals subset sum

// Memoization
class Solution {
public:
    int solve(int index, int sum, vector<int> &nums, vector<vector<int>> &dp) {
        if(sum==0) return 1;
        if(index==0) return sum==nums[0];
        if(dp[index][sum]!=-1) return dp[index][sum];
        int pick = 0;
        if(sum>=nums[index]) pick = solve(index-1, sum-nums[index], nums, dp);
        int notPick = solve(index-1, sum, nums, dp);
        return dp[index][sum] = (pick || notPick) ? 1 : 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; ++i) sum += nums[i];
        if(sum%2==1) return false;
        sum = sum/2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        int ans = solve(n-1, sum, nums, dp);
        return ans==1;
    }
};