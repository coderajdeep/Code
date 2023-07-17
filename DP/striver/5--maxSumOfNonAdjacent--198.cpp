// leetcode 198
// House robber - leetcode
// Max sum of non adjacent element - coding ninja

// leetcode solution
// Space optimized Bottom up approach - tabulation
// Time O(n)
// Space O(1)
// Edge case, n==1 and n==2
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        int curr = prev1;
        
        for(int i=2; i<n; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};


// Time O(n)
// Space O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = nums[0];
        if(n==1) return prev2;
        int prev = max(nums[0], nums[1]);
        if(n==2) return prev;
        for(int index=2; index<n; ++index) {
            int pick = nums[index] + prev2;
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

// leetcode solution
// Bottom up approach - tabulation
// Time O(n)
// Space O(n) [array O(n)]

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; ++i) {
            int pick = nums[i] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
};

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