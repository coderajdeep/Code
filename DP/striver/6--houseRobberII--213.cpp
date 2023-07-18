// Leetcode 213
// House Robber II

// leetcode solution
// Space optimized Bottom up approach - tabulation
// Time O(n)
// Space O(1)
// Edge case, n==1 and n==2
class Solution {
public:
    // solve function will work when st<end
    int solve(vector<int> &nums, int st, int end) {
        int prev2 = nums[st];
        int prev1 = max(nums[st], nums[st+1]);
        int curr = prev1;
        for(int i=st+2; i<=end; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0], nums[1]);
        int exculdeLast = solve(nums, 0, n-2);
        int excludeFirst = solve(nums, 1, n-1);
        return max(excludeFirst, exculdeLast);
    }
};


// Code studio (house-robber_839733)
// Space optimized Bottom up approach - tabulation
// Time O(n)
// Space O(1)
// Edge case, n==1 and n==2
long long solve(vector<int> &nums, int st, int end) {
    long long prev2 = nums[st];
    long long prev1 = max(nums[st], nums[st+1]);
    long long curr = prev1;
    for(int i=st+2; i<=end; ++i) {
        long long pick = prev2 + nums[i];
        long long notPick = prev1;
        curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    if(n==2) return max(valueInHouse[0], valueInHouse[1]);
    return max(solve(valueInHouse, 0, n-2), solve(valueInHouse, 1, n-1));
}


// Top down approach
// Memoization
// Time complexity O(n)
// Space complexity O(n)
int solve(int startIndex, int endIndex, vector<int>& nums, vector<int>& dp) {
    if(startIndex>endIndex) return 0;
    if(startIndex==endIndex) return nums[startIndex];
    if(dp[endIndex]!=-1) return dp[endIndex];
    int pick = solve(startIndex, endIndex-2, nums, dp) + nums[endIndex];
    int notPick = solve(startIndex, endIndex-1, nums, dp);
    dp[endIndex] = max(pick, notPick);
    return dp[endIndex];
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp1(n, -1), dp2(n, -1);
    int excludeLast = solve(0, n-2, nums, dp1);
    int excludeFirst = solve(1, n-1, nums, dp2);
    int ans = max(excludeLast, excludeFirst);
    return ans;
}