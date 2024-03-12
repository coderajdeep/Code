// 0 1 Knapsack -- coding ninjas
// Memoization
// Time complexity O(n*maxWeight)
// Space complexity O(n*maxWeight) + Recursion stack space 0(n)
int getMaxAmount(int index, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {
	if(W==0) return 0;
	if(index==0) {
		if(W>=weight[0]) return value[0];
		else return 0;
	}
	if(dp[index][W] != -1) return dp[index][W];
	int pick = INT_MIN;
	if(weight[index]<=W) pick = value[index] + getMaxAmount(index-1, W-weight[index], weight, value, dp);
	int notPick = getMaxAmount(index-1, W, weight, value, dp);
	return dp[index][W] = max(pick, notPick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return getMaxAmount(n-1, maxWeight, weight, value, dp);
}

// Tabulation
// Time complexity O(n*maxWeight)
// Space complexity O(n*maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	int dp[n][maxWeight+1];
	for(int i=0; i<n; ++i) {
		for(int j=0; j<=maxWeight; ++j) {
			if(j==0) dp[i][j] = 0;
			else if(i==0) {
				if(weight[0]<=j) dp[0][j] = value[0];
				else dp[i][j] = 0;
			}
			else {
				int pick = (weight[i]<=j) ? (value[i] + dp[i-1][j-weight[i]]) : INT_MIN;
				int notPick = dp[i-1][j];
				dp[i][j] = max(pick, notPick);
			}
		}
	}
	return dp[n-1][maxWeight];
}

// Space optimized
// Time complexity O(n*maxWeight)
// Space complexity O(maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	int prev[maxWeight+1];
	int curr[maxWeight+1];
	prev[0] = curr[0] = 0;
	for(int i=1; i<=maxWeight; ++i) {
		if(weight[0]<=i) prev[i] = value[0];
		else prev[i] = 0;
	}
	for(int i=1; i<n; ++i) {
		for(int j=1; j<=maxWeight; ++j) {
			int pick = (weight[i]<=j) ? (value[i] + prev[j-weight[i]]) : INT_MIN;
			int notPick = prev[j];
			curr[j] = max(pick, notPick);
		}
		for(int j=1; j<=maxWeight; ++j) prev[j] = curr[j];
	}
	return prev[maxWeight];
}