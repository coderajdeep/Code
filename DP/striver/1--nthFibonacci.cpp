// leetcode 509
// n-th fibonacci number

// Top-down approach
// Memoization
// Time complexity --> O(n)
// Space complexity --> recursion stack space O(n) + external space O(n)
int solve(int n, vector<int> &dp) {
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}
    
int fib(int n) {
    if(n<=1) return n;
    vector<int>dp(n+1, -1);
    return solve(n, dp);
}


// Bottom-up approach
// Tabulation
// Time complexity --> O(n)
// Space complexity --> O(n)
int fib(int n) {
    if(n<=1) return n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


// Space optimized Bottom-up approach
// Space optimized Tabulation
// Time complexity --> O(n)
// Space complexity --> O(1)

int fib(int n) {
    if(n<=1) return n;
    int prev2 = 0;
    int prev = 1;
    int curr;
    for(int i=2; i<=n; ++i) {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}