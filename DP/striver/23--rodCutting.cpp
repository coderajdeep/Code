// Rod cutting
// Similar to unbounded knapasck

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