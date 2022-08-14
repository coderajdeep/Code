// C
// Atcoder DP
// Vacation
// https://atcoder.jp/contests/dp/tasks/dp_c
// https://atcoder.jp/contests/dp/submissions/34053356

// Time complexity O(n)
// Space complexity O(n) [Function call stack O(n) + Array O(n)]

#include<bits/stdc++.h>
using namespace std;
#define N 100000
int arr[N][3];
int dp[N][3];

void init(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<3; ++j) dp[i][j] = -1;
    }
}

int solve(int n, int m) {
    if(n==0) return arr[0][m];
    if(dp[n][m]!=-1) return dp[n][m];
    int value;
    if(m==0) value = max(solve(n-1, 1), solve(n-1, 2));
    else if(m==1) value = max(solve(n-1, 0), solve(n-1, 2));
    else if(m==2) value = max(solve(n-1, 0), solve(n-1, 1));
    return dp[n][m] = value + arr[n][m];
}

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<3; ++j) cin>>arr[i][j];
    }
    int ans = INT_MIN;
    for(int i=0; i<3; ++i) {
        init(n);
        ans = max(ans, solve(n-1, i));
    }
    cout<<ans<<endl;
}