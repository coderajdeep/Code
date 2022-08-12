// Coding ninjas
// striver dp series

// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// tabulation / Bottom up approach
// Time O(n)
// Space O(n)
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i=2; i<n; ++i) {
        int one = dp[i-1] + abs(heights[i]-heights[i-1]);
        int two = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(one, two);
    }
    return dp[n-1];
}

// Memoization / Top down approach
// Time O(n)
// Space O(n) [function call stack O(n) + array O(n)]
// asuming n as an index
int solve(int n, vector<int> &ht, vector<int> &dp) {
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left = solve(n-1, ht, dp) + abs(ht[n]-ht[n-1]);
    int right = INT_MAX;
    if(n>1) right = solve(n-2, ht, dp) + abs(ht[n]-ht[n-2]);
    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    return solve(n-1, heights, dp);
}

// Memoization / Top down approach
// Time O(n)
// Space O(n) [function call stack O(n) + array O(n)]
// asuming n as a size
int solve(int n, vector<int> &ht, vector<int> &dp) {
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    int left = solve(n-1, ht, dp) + abs(ht[n-1]-ht[n-2]);
    int right = INT_MAX;
    if(n>2) right = solve(n-2, ht, dp) + abs(ht[n-1]-ht[n-3]);
    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return solve(n, heights, dp);
}