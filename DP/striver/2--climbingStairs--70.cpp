// leetcode 70
// climbing stairs

// this is similar to fibonacci (leetcode 509)

// https://youtu.be/A6mOASLl2Dg
// https://youtu.be/mLfjzJsN8us

// Top-down approach
// Memoization
// Time complexity --> O(n)
// Space complexity --> recursion stack space O(n) + external space O(n)
int solve(int n, vector<int>&dp) {
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int climbStairs(int n) {
    if(n==0 || n==1) return 1;
    vector<int>dp(n+1, -1);
    return solve(n, dp);
}