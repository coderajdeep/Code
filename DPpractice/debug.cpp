#include<bits/stdc++.h>
using namespace std;

int isSubSetSum(int arr[], vector<int> &dp, int n, int sum) {
    if(n==0) {
        return 0;
    }
    if(arr[n-1]==sum) {
        return 1;
    }
    
    if(dp[n]!=-1) {
        cout<<dp[n]<<" ";
        return dp[n];
    }
    
    if(arr[n-1]>sum) {
        dp[n] = isSubSetSum(arr, dp, n-1, sum);
    }
    else {
        dp[n] = (isSubSetSum(arr, dp, n-1, sum-arr[n-1])==1 or isSubSetSum(arr, dp, n-1, sum)==1) ? 1 : 0;
    }
    cout<<dp[n]<<" ";
    return dp[n];
}

int main() {
    int n = 6;
    int sum = 9;
    int arr[] = {3, 34, 4, 12, 5, 2};
    vector<int>dp(n+1, -1);
    cout<<isSubSetSum(arr, dp, n, sum)<<endl;
    return 0;
}