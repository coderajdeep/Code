// Rod cutting
// Similar to unbounded knapasck


// Space optimized
// 1D array
int cutRod(vector<int> &price, int n) {
	int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; ++i) dp[i] = price[0]*i;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=n; ++j) {
            int take = 0;
            if((i+1)<=j) take = price[i] + dp[j-i-1];
            int notTake = dp[j];
            dp[j] = max(take, notTake);
        }
    }
    return dp[n];
}

// Space optimized tabulation
int cutRod(vector<int> &price, int n) {
	int prev[n+1];
    int curr[n+1];
    curr[0] = 0;
    for(int i=0; i<=n; ++i) prev[i] = price[0]*i;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=n; ++j) {
            int take = 0;
            if((i+1)<=j) take = price[i] + curr[j-i-1];
            int notTake = prev[j];
            curr[j] = max(take, notTake);
        }
        for(int i=1; i<=n; ++i) prev[i] = curr[i];
    }
    return prev[n];
}



// Bottom up approach
// Tabulation
int cutRod(vector<int> &price, int n) {
	int dp[n][n+1];
    for(int i=0; i<=n; ++i) dp[0][i] = price[0]*i;
    for(int i=1; i<n; ++i) {
        dp[i][0] = 0;
        for(int j=1; j<=n; ++j) {
            int take = 0;
            if((i+1)<=j) take = price[i] + dp[i][j-i-1];
            int notTake = dp[i-1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][n];
}


// Top down approach
// Memoization
int solve(int index, int len, vector<int> &price, vector<vector<int>> &dp) {
    if(len==0) return 0;
    if(index==0) return len*price[0];
    if(dp[index][len]!=-1) return dp[index][len];
    int take = 0;
    if((index+1)<=len) take = price[index] + solve(index, len-index-1, price, dp);
    int notTake = solve(index-1, len, price, dp);
    return dp[index][len] = max(take, notTake);
}

int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
    int ans = solve(n-1, n, price, dp);
    return ans;
}