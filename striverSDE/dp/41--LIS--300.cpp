// Longest Increasing Subsequence -- leetcode 300

// Time complexity O(n*n)
// Space complexity O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), maxLen = 1;
    vector<int> dp(n, 1);
    // dp[i] --> max length subsequence which ends in i index
    for(int currIndex=1; currIndex < n; ++currIndex) {
        for(int prevIndex=0; prevIndex < currIndex; ++prevIndex) {
            if(nums[prevIndex] < nums[currIndex] && ((dp[prevIndex] + 1) > dp[currIndex])) {
                dp[currIndex] = dp[prevIndex] + 1;
            }
        }
        if(maxLen < dp[currIndex]) maxLen = dp[currIndex];
    }
    return maxLen;
}

// Time complexity O(n*n)
// Space complexity O(n*n) + O(n) Recursion stack space
int getLIS(int index, int prev, vector<int> &nums, vector<vector<int>> &dp) {
    if(index==nums.size()) return 0;
    if(dp[index][prev] != -1) return dp[index][prev];
    int pick = 0;
    if(prev==0 || nums[prev-1]<nums[index]) {
        pick = 1 + getLIS(index+1, index+1, nums, dp);
    }
    int notPick = getLIS(index+1, prev, nums, dp);
    return dp[index][prev] = max(pick, notPick);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return getLIS(0, 0, nums, dp);
}