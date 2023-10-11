// Frog Jump with k distance -- Coding Ninjas

// Memoization - top down approach
// Time complexity O(n*k)
// Space complexity O(n)
// Considering recursion stack space, then space complexity O(n*k)
int solve(int index, int k, vector<int> &height, vector<int> &dp) {
    if(index==0) {
        return 0;
    }
    if(dp[index]!=-1) {
        return dp[index];
    }
    int minValue = INT_MAX;
    for(int i=1; i<=k; ++i) {
        if(index>=i) {
            int prevValue = solve(index-i, k, height, dp);
            minValue = min(minValue, prevValue + abs(height[index]-height[index-i])); 
        }
    }
    return dp[index] = minValue;
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n, -1);
    int ans = solve(n-1, k, height, dp);
    return ans;
}


// Tabulation - bottom up approach
// Time complexity O(n*k)
// Space complexity O(n)
int minimizeCost(int n, int k, vector<int> &height){
    int dp[n];
    dp[0] = 0;
    if(n==1) return dp[0];
    for(int i=1; i<n; ++i) {
        int minVal = INT_MAX;
        for(int j=1; j<=k; ++j) {
            if(i>=j) {
                minVal = min(minVal, (dp[i-j] + abs(height[i] - height[i-j])));
            }
        }
        dp[i] = minVal;
    }
    return dp[n-1];
}