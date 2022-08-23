// Geeks and Coding Ninja
// partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494


// Space optimized tabulation
// edge case n == 1, need to dry run to understand
int minSubsetSumDifference(vector<int>& arr, int n) {
	int sum = 0;
    for(int i=0; i<n; ++i) sum += arr[i];
    bool prev[sum+1];
    bool curr[sum+1];
    prev[0] = true;
    for(int i=1; i<=sum; ++i) prev[i] = (arr[0]==i);
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=sum; ++j) {
            bool pick = false;
            if(j>=arr[i]) pick = prev[j-arr[i]];
            bool notPick = prev[j];
            curr[j] = (pick || notPick);
        }
        for(int k=1; k<=sum; ++k) prev[k] = curr[k];
    }
    int ans = 1e9;
    for(int i=0; i<=sum; ++i) {
        if(prev[i]) ans = min(ans, abs(sum - 2*i));
    }
    return ans;
}



// Tabulation
int minSubsetSumDifference(vector<int>& arr, int n) {
	int sum = 0;
    for(int i=0; i<n; ++i) sum += arr[i];
    bool dp[n][sum+1];
    for(int i=0; i<n; ++i) dp[i][0] = true;
    for(int i=0; i<=sum; ++i) dp[0][i] = (arr[0]==i);
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=sum; ++j) {
            bool pick = false;
            if(j>=arr[i]) pick = dp[i-1][j-arr[i]];
            bool notPick = dp[i-1][j];
            dp[i][j] = (pick || notPick);
        }
    }
    int ans = 1e9;
    for(int i=0; i<=sum; ++i) {
        if(dp[n-1][i]) ans = min(ans, abs(sum - 2*i));
    }
    return ans;
}
