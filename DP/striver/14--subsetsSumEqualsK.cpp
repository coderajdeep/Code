// coding ninjas
// codestudio/problems/subset-sum-equal-to-k_1550954

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