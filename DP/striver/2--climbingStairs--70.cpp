// leetcode 70
// climbing stairs

// this is similar to fibonacci (leetcode 509)

// https://youtu.be/A6mOASLl2Dg
// https://youtu.be/mLfjzJsN8us

// Top-down approach
// Memoization
// Time complexity --> O(n)
// Space complexity --> recursion stack space O(n) + external space O(n)
int solve(int n, vector<int> &dp) {
    if(n<=2) {
        return n;
    }
    if(dp[n]!=-1) {
        return dp[n];
    }
    dp[n] = solve(n-1, dp) + solve(n-2, dp);
    return dp[n]; 
}

int climbStairs(int n) {
    if(n<=2) {
        return n;
    }
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    return ans;
}


// Bottom-up approach
// Tabulation
// Time complexity --> O(n)
// Space complexity --> O(n)
int climbStairs(int n) {
    if(n<=2) return n;
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


// Space optimized Bottom-up approach
// Space optimized Tabulation
// Time complexity --> O(n)
// Space complexity --> O(1)
int climbStairs(int n) {
    int prev2 = 1;
    if(n==1) return prev2;
    int prev = 2;
    if(n==2) return prev;
    for(int i=3; i<=n; ++i) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


// https://www.codingninjas.com/studio/problems/count-ways-to-reach-the-n-th-stairs_798650
// Time complexity O(n)
// Space complexity O(1)

int countDistinctWays(int nStairs) {
    int mod = 1e9+7;
    int prev2 = 1;
    if(nStairs==0) return prev2;
    int prev = 1;
    if(nStairs==1) return prev;
    for(int i=2; i<=nStairs; ++i) {
        int curr = (prev + prev2)%mod;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}