// House Robber II -- leetcode 213

int solve(int start, int end, vector<int>& nums, vector<int>& dp) {
    if(start == end) {
        return nums[start];
    }
    else if((start+1) == end) {
        return max(nums[start], nums[start+1]);
    }
    if(dp[end]!=-1) {
        return dp[end];
    }
    int pick = solve(start, end-2, nums, dp) + nums[end];
    int notPick = solve(start, end-1, nums, dp);

    return dp[end] = max(pick, notPick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp1(n, -1), dp2(n, -1);
    int ans = max(solve(0, n-2, nums, dp1), solve(1, n-1, nums, dp2));
    return ans;
}