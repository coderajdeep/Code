// leetcode 1092
// Shortest Common Supersequence

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int dp[n1+1][n2+1];
        for(int i=0; i<=n2; ++i) dp[0][i] = 0;
        for(int i=1; i<=n1; ++i) {
            dp[i][0] = 0;
            for(int j=1; j<=n2; ++j) {
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        int len = n1 + n2 - dp[n1][n2];
        int index = len-1, i = n1, j = n2;
        string s(len, '#');
        while(i>0 && j>0 && index>=0) {
            if(str1[i-1]==str2[j-1]) {
                s[index] = str1[i-1];
                --index; --i; --j;
            }
            else if(dp[i][j-1]>dp[i-1][j]) {
                s[index] = str2[j-1];
                --index; --j;
            }
            else {
                s[index] = str1[i-1];
                --index; --i;
            }
        }
        while(i>0 && index>=0) {
            s[index] = str1[i-1];
            --index; --i;
        }
        while(j>0 && index>=0) {
            s[index] = str2[j-1];
            --index; --j;
        }
        return s;
    }
};