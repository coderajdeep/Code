// Longest common substring
// Geeks


// Space optimized
// tabulation
int longestCommonSubstr (string S1, string S2, int n, int m) {
    int dp[2][m+1];
    for(int i=0; i<=m; ++i) dp[0][i] = 0;
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if(S1[i-1]==S2[j-1]) dp[1][j] = 1 + dp[0][j-1];
            else dp[1][j] = 0;
            ans = max(ans, dp[1][j]);
        }
        for(int i=1; i<=m; ++i) dp[0][i] = dp[1][i];
    }
    return ans;
}

// Bottom up approach
// Tabulation
int longestCommonSubstr (string S1, string S2, int n, int m) {
    int dp[n+1][m+1];
    int ans = 0;
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(S1[i-1]==S2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}