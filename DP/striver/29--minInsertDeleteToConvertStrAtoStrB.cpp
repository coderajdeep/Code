// Minimum Insertion/Deletion is required to conver a string A to string B
// Space optimized Tabulation
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
int minOperations(string str1, string str2) { 
    int n = str1.size();
    int m = str2.size();
    int dp[2][m+1];
    for(int i=0; i<=m; ++i) dp[0][i] = 0;
    dp[1][0] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(str1[i-1]==str2[j-1]) dp[1][j] = 1 + dp[0][j-1];
            else dp[1][j] = max(dp[1][j-1], dp[0][j]);
        }
        for(int i=1; i<=m; ++i) dp[0][i] = dp[1][i];
    }
    return (n + m - (2*dp[0][m]));
}