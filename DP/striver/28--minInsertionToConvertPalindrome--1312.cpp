// Leetcode 1312
// Minimum Insertion Steps to Make a String Palindrome
// Space optimized Tabulation
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string str(s.rbegin(), s.rend());
        int dp[2][n+1];
        for(int i=0; i<=n; ++i) dp[0][i] = 0;
        for(int i=1; i<=n; ++i) {
            dp[1][0] = 0;
            for(int j=1; j<=n; ++j) {
                if(s[i-1]==str[j-1]) dp[1][j] = 1 + dp[0][j-1];
                else dp[1][j] = max(dp[1][j-1], dp[0][j]);
            }
            for(int i=1; i<=n; ++i) dp[0][i] = dp[1][i];
        }
        return (n-dp[0][n]);
    }
};