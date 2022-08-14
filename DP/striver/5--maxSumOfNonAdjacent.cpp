// leetcode 198
// House robber
// Max sum of non adjacent element

// leetcode solution
// Top down approach - Memoization
// Time O(n)
// Space O(n) [function call stack O(n) + array O(n)]
class Solution {
public:
    
    int solve(int index, vector<int> &nums, vector<int> &dp) {
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index] + solve(index-2, nums, dp);
        int notPick = solve(index-1, nums, dp);
        return dp[index] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n-1, nums, dp);
    }
};


// coding ninja solution
// Top down approach - Memoization
// Time O(n)
// Space O(n) [function call stack O(n) + array O(n)]
int solve(int index, vector<int> &nums, vector<int> &dp) {
    if(index==0) return nums[0];
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int pick = nums[index] + solve(index-2, nums, dp);
    int notPick = solve(index-1, nums, dp);
    return dp[index] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n-1, nums, dp);
}