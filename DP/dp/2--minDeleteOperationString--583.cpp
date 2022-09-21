// leetcode - 583
// Delete Operation for Two Strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[2][m+1];
        for(int i=0; i<=m; ++i) dp[0][i] = 0;
        for(int i=1; i<=n; ++i) {
            dp[1][0] = 0;
            for(int j=1; j<=m; ++j) {
                if(word1[i-1]==word2[j-1]) dp[1][j] = 1 + dp[0][j-1];
                else dp[1][j] = max(dp[1][j-1], dp[0][j]);
            }
            for(int i=1; i<=m; ++i) dp[0][i] = dp[1][i];
        }
        return (m+n-(2*dp[0][m]));
    }
};