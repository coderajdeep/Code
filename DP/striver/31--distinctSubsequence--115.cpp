// leetcode 115
// Distinct Subsequences

// Most space optimized way
// tabulation
// Using one 1D array
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        unsigned int dp[m+1];
        for(int i=1; i<=m; ++i) dp[i] = 0;
        dp[0] = 1;
        for(int i=1; i<=n; ++i) {
            for(int j=m; j>=1; --j) {
                if(s[i-1]==t[j-1]) dp[j] = dp[j-1] + dp[j];
                // we don't need to consider else case
                // because else dp[j] = dp[j] that does not chnage anything
            }
        }
        return dp[m];
    }
};


// Space optimized 
// tabulation
// using two 1D array
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        unsigned int dp[2][m+1];
        for(int i=1; i<=m; ++i) dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i=1; i<=n; ++i) {
            dp[1][0] = 1;
            for(int j=1; j<=m; ++j) {
                if(s[i-1]==t[j-1]) dp[1][j] = dp[0][j-1] + dp[0][j];
                else dp[1][j] = dp[0][j];
            }
            for(int i=1; i<=m; ++i) dp[0][i] = dp[1][i];
        }
        return dp[0][m];
    }
};


// Bottom up approach
// Tabulation
/*
Below test case was failing while taking int dp[n+1][m+1]
"xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo"
"rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys"
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        unsigned int dp[n+1][m+1];
        for(int i=1; i<=m; ++i) dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i=1; i<=n; ++i) {
            dp[i][0] = 1;
            for(int j=1; j<=m; ++j) {
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};

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