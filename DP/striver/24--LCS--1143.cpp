// Longest common subsequence
// leetcode 1143

// Top down approach
// Memoization
class Solution {
public:
    int solve(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp) {
        if(n1==0 || n2==0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1-1]==s2[n2-1]) return dp[n1][n2] = 1 + solve(n1-1, n2-1, s1, s2, dp);
        return dp[n1][n2] = max(solve(n1-1, n2, s1, s2, dp), solve(n1, n2-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        int ans = solve(n1, n2, text1, text2, dp);
        return ans;
    }
};