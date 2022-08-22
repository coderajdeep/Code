// coding ninjas
// codestudio/problems/subset-sum-equal-to-k_1550954

// Space optimized tabulation 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    bool prev[k+1];
    bool curr[k+1];
    prev[0] = true;
    for(int i=1; i<=k; ++i) prev[i] = (arr[0]==i);
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=k; ++j) {
            if(j==0) curr[j] = true;
            else {
                bool pick = false;
                if(j>=arr[i]) pick = prev[j-arr[i]];
                bool notPick = prev[j];
                curr[j] = pick || notPick;
            }
        }
        for(int j=1; j<=k; ++j) prev[j] = curr[j];
    }
    return curr[k];
}


// Tabulation - Bottom up approach
bool subsetSumToK(int n, int k, vector<int> &arr) {
    bool dp[n][k+1];
    for(int i=0; i<n; ++i) dp[i][0] = true;
    for(int i=1; i<=k; ++i) dp[0][i] = (arr[0]==i);
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=k; ++j) {
            bool notPick = dp[i-1][j];
            bool pick = false;
            if(j>=arr[i]) pick = dp[i-1][j-arr[i]];
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n-1][k];
}

// Memoization - Top down approach
int solve(int index, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if(sum==0) return 1;
    if(index==0) return ((arr[0]==sum)?1:0);
    if(dp[index][sum]!=-1) return dp[index][sum];
    int pick = (sum>=arr[index])?solve(index-1, sum-arr[index], arr, dp):0;
    int notPick = solve(index-1, sum, arr, dp);
    return dp[index][sum] = (pick || notPick) ? 1 : 0;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    int ans = solve(n-1, k, arr, dp);
    return ans==1;
}