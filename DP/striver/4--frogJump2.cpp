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
// Space O(n)


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


// Coding Ninja - https://www.codingninjas.com/studio/problems/minimal-cost_8180930
// Tob down approach - Memoization
// Time complexity - O(n*k)
// Space complexity - O(n) array + O(n) function call stack
int solve(int index, int k, vector<int> &ht, vector<int> &dp) {
    if(index==0) return 0;
    if(index==1) return abs(ht[1]-ht[0]);
    if(dp[index]!=-1) return dp[index];
    int minValue = 1e9;
    for(int i=1; i<=k; ++i) {
        if(index-i<0) break; // this jumps is not possible
        int val = solve(index-i, k, ht, dp) + abs(ht[index]-ht[index-i]);
        minValue = min(minValue, val);
    }
    return dp[index] = minValue;
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, -1);
    int ans = solve(n-1, k, height, dp);
    return ans;
}


// Bottom up approach - tabulation method
// Time complexity - O(n*k)
// Space complexity - O(n)
int minimizeCost(int n, int k, vector<int> &height){
    int dp[n];
    dp[0] = 0;
    if(n==1) return 0;
    dp[1] = abs(height[1]-height[0]);
    if(n==2) return dp[n];
    for(int index=2; index<n; ++index) {
        int minValue = 1e9;
        for(int i=1; i<=k; ++i) {
            if(index-i<0) break;
            int val = abs(height[index]-height[index-i]) + dp[index-i];
            minValue = min(minValue, val);
        }
        dp[index] = minValue;
    }
    return dp[n-1];
}