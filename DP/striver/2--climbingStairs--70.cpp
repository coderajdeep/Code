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
    if(n<=2) return n;
    int prev2 = 1;
    int prev1 = 2;
    int curr;
    for(int i=3; i<=n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}