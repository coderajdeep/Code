// leetcode 115
// Distinct Subsequences

// Top down approach
// Memoization
class Solution {
public:
    int solve(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]) {
            int include = solve(n-1, m-1, s, t, dp);
            int notInclude = solve(n-1, m, s, t, dp);
            return dp[n][m] = include + notInclude;
        }
        else {
            return dp[n][m] = solve(n-1, m, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = solve(n, m, s, t, dp);
        return ans;
    }
};