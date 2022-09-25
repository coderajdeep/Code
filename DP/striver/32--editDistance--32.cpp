// leetcode 72
// Edit distance


// Space optimized 
// Bottom up approach
// tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[2][m+1];
        for(int i=0; i<=m; ++i) dp[0][i] = i;
        for(int i=1; i<=n; ++i) {
            dp[1][0] = i;
            for(int j=1; j<=m; ++j) {
                if(word1[i-1]==word2[j-1]) dp[1][j] = dp[0][j-1];
                else dp[1][j] = 1 + min({dp[0][j-1], dp[1][j-1], dp[0][j]});
                // replace : dp[0][j-1]; insert : dp[1][j-1]; delete : dp[0][j]
            }
            for(int i=0; i<=m; ++i) dp[0][i] = dp[1][i];
        }
        return dp[0][m];
    }
};

// Bottom up approach
// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=m; ++i) dp[0][i] = i;
        for(int i=0; i<=n; ++i) dp[i][0] = i;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                // replace : dp[i-1][j-1]; insert : dp[i][j-1]; delete : dp[i-1][j]
            }
        }
        return dp[n][m];
    }
};

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