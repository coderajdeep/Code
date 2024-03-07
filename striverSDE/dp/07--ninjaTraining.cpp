// Ninja's training ***

// Space optimized
// Best solution
// Time complexity O(n * 12) ~ O(n)
// Space complexity O(8) ~ constant
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0), curr(4);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<4; ++j) {
			int val = INT_MIN;
			for(int k=0; k<3; ++k) {
				if(j != k) {
					int point = points[i][k] + prev[k];
					val = max(val, point);
				}
			}
			curr[j] = val;
		}
		for(int index=0; index<4; ++index) {
			prev[index] = curr[index];
		}
	}
	return prev[3];
}

// Top down approach
// Memoization
// Time complexity O(n * 12) ~ O(n)
// Space complexity O(n)
// Recursion stack space O(n)
int ninjaUtils(int index, int nextDayIndex, vector<vector<int>> &points, vector<vector<int>> &dp) {
	if(index < 0) return 0;
	if(dp[index][nextDayIndex] != -1) return dp[index][nextDayIndex];
	int val = INT_MIN;
	for(int i=0; i<3; ++i) {
		if(i!=nextDayIndex) {
			int pointCollected = points[index][i] + ninjaUtils(index-1, i, points, dp);
			val = max(val, pointCollected);
		}
	}
	return dp[index][nextDayIndex] = val;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
	vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaUtils(n-1, 3, points, dp);
}

// Bottom up approach
// Tabulation
// Time complexity O(n * 12) ~ O(n)
// Space complexity O(n * 12) ~ O(n)
int ninjaTraining(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(n+1, vector<int>(4, 0));
    for(int i=1; i<=n; ++i) {
		// next day task
		for(int j=0; j<4; ++j) {
			int val = INT_MIN;
			// current day task
			for(int k=0; k<3; ++k) {
				// we can not do same task in two consecutive day
				if(j != k) {
					int pointsCollected = points[i-1][k] + dp[i-1][k];
					val = max(val, pointsCollected);
				}
			}
			dp[i][j] = val;
		}
	}
	return dp[n][3];
}