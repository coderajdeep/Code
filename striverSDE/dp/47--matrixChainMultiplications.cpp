// Matrix Chain Multiplications -- Coding Ninjas
// Time complexity O(n*n*n)
// Space complexity O(n*n) + O(n) Recursion stack space
int getMinMultiplication(int i, int j, int *arr, vector<vector<int>> &dp) {
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int minOperation = INT_MAX;
    for(int k=i; k<j; ++k) {
        int firstPartition = getMinMultiplication(i, k, arr, dp);
        int secondPartition = getMinMultiplication(k+1, j, arr, dp);
        int total = firstPartition + secondPartition + arr[i-1]*arr[k]*arr[j];
        // final matrix dimension will be arr[i-1] * arr[j]
        // so multiplication required for getting the final matrix
        // arr[i-1] * arr[k] * arr[j]
        minOperation = min(minOperation, total);
    }
    return dp[i][j] = minOperation;
}

int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return getMinMultiplication(1, n, arr, dp);
}