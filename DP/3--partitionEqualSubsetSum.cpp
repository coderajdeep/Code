
// Bottom up approacj - tabulation

class Solution{
public:

    bool isSubsetSum(int arr[], int n, int sum) {
        if(sum==0) {
            return true;
        }
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        
        for(int i=0; i<=n; ++i) {
            dp[i][0] = true;
        }
        for(int i=1; i<=sum; ++i) {
            dp[0][i] = false;
        }
        
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=sum; ++j) {
                if(arr[i-1]>j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        if(N==0) {
            return 0;
        }
        
        long sum = 0;
        for(int i=0; i<N; ++i) {
            sum += arr[i];
        }
        
        if(sum%2==1) {
            return 0;
        }
        
        return isSubsetSum(arr, N, sum/2) ? 1 : 0;
    }
};



// Top down approach - memoization

class Solution {
    public:
    int subsetSum(int arr[], int n, int sum, vector<vector<int>> &dp) {
        
        if(sum==0) {
            return 1;
        }
        
        if(n==0) {
            return 0;
        }
        
        if(dp[n][sum]!=-1) {
            return dp[n][sum];
        }
        
        if(arr[n-1]>sum) {
            return dp[n][sum] = subsetSum(arr, n-1, sum, dp);
        }
        
        return dp[n][sum] = (subsetSum(arr, n-1, sum-arr[n-1], dp)==1 or subsetSum(arr, n-1, sum, dp)==1) ? 1 : 0;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        if(N==0) {
            return 0;
        }
        
        long sum = 0;
        
        for(int i=0; i<N; ++i) {
            sum += arr[i];
        }
        
        if(sum%2==1) {
            return 0;
        }
        
        sum /= 2;
        
        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        
        return subsetSum(arr, N, sum, dp);
    }
};