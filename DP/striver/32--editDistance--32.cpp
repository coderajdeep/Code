// leetcode 72
// Edit distance

// Top down approach
// Mamoization
class Solution {
public:
    int solve(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(n==0 && m==0) return 0;
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]) return dp[n][m] = solve(n-1, m-1, s1, s2, dp);
        else {
            int rep = solve(n-1, m-1, s1, s2, dp);
            int del = solve(n-1, m, s1, s2, dp);
            int in = solve(n, m-1, s1, s2, dp);
            return dp[n][m] = 1 + min({rep, del, in});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = solve(n, m, word1, word2, dp);
        return ans;
    }
};