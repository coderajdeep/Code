

// bottom up approach -- tabulation

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        if(N==0 or sum==0) {
            return 0;
        }
        
        vector<vector<bool>> dp(N+1, vector<bool>(sum+1));
        
        for(int i=0; i<=N; ++i) {
            dp[i][0] = false;
        }
        for(int i=1; i<=sum; ++i) {
            dp[0][i] = false;
        }
        
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=sum; ++j) {
                
                if(arr[i-1]==j) {
                    dp[i][j] = true;
                }
                else if(j<arr[i-1]) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = (dp[i-1][j] or dp[i-1][j-arr[i-1]]);
                }
            }
        }
        
        return dp[N][sum];
    }
};



// top down approach -- memoization

class Solution{   
public:
    
    int solve(int arr[], vector<vector<int>> &dp, int n, int sum) {
        if(n==0 || sum==0) {
            return 0;
        }
        if(sum==arr[n-1]) {
            return 1;
        }
        
        if(dp[n][sum]!=-1) {
            return dp[n][sum];
        }
        
        if(sum<arr[n-1]) {
            return dp[n][sum] = solve(arr, dp, n-1, sum);
        }
        
        return dp[n][sum] = (solve(arr, dp, n-1, sum-arr[n-1])==1 or solve(arr, dp, n-1, sum)==1) ? 1 : 0;
    }

    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        if(N==0 || sum==0) {
            return false;
        }
        if(sum==arr[N-1]) {
            return true;
        }
        
        vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
        
        int val = solve(arr, dp, N, sum);
        
        return val==1 ? true : false;
    }
};
