// Print longest common subsequence
// hackerrank
// https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
// https://www.techiedelight.com/longest-common-subsequence-finding-lcs/
// ToDo : Print all LCS

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    for(int i=0; i<=m; ++i) dp[0][i] = 0;
    for(int i=1; i<=n; ++i) {
        dp[i][0] = 0;
        for(int j=1; j<=m; ++j) {
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int len = dp[n][m];
    vector<int>ans(len);
    int index = len-1;
    while(n>0 && m>0 && index>=0) {
        if(a[n-1]==b[m-1]) {
            ans[index--] = a[n-1];
            --n; --m;
        }
        else if(dp[n-1][m]>dp[n][m-1]) --n;
        else --m;
    }
    return ans;
}