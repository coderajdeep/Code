// Atcoder
// striver dp series

// https://atcoder.jp/contests/dp/tasks/dp_b

// Top down approach - Memoization
// Time O(n*k)
// Space O(n) [function call stack O(n) + array O(n)]

// submission link
// https://atcoder.jp/contests/dp/submissions/33978496

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solve(int index, int k, vector<int> &ht, vector<int> &dp) {
    if(index==0) return 0;
    if(dp[index]!=-1) return dp[index];
    int minValue = INT_MAX;
    for(int j=1; j<=k; ++j) {
        if(index-j>=0) {
            minValue = min(minValue, solve(index-j, k, ht, dp) + abs(ht[index] - ht[index-j]));
        }
        else {
            break;
        }
    }
    return dp[index] = minValue;
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> ht(n);
    for(int i=0; i<n; ++i) cin>>ht[i];
    vector<int> dp(n, -1);
    cout<<solve(n-1, k, ht, dp)<<endl;
}



// Tabulation / Bottom up approach
// Time O(n*k)
// Space O(n) [function call stack O(n) + array O(n)]


int solve(int index, int k, vector<int> &ht, vector<int> &dp) {
    dp[0] = 0;
    for(int i=0; i<=index; ++i) {
        int minValue = INT_MAX;
        for(int j=1; j<=k; ++j) {
            if(i+j<=index) {
                minValue = min(minValue, dp[i] + abs(ht[i] - ht[i+j]));
            }
            else {
                break;
            }
        }
        dp[j] = minValue;
    }
    return dp[n-1];
}