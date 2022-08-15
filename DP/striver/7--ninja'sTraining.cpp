// Coding Ninja
// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003


// Tabulation - Bottom up approach
// Time - O(n*12) - Overall O(n)
// Space - O(n*4) - Overall O(n)
int ninjaTraining(int n, vector<vector<int>> &points) {
    int dp[n][4];
    for(int i=0; i<4; ++i) {
        int value = INT_MIN;
        for(int j=0; j<3; ++j) {
            if(i!=j) value = max(points[0][j], value);
        }
        dp[0][i] = value;
    }
    
    for(int i=1; i<n; ++i) {
        for(int j=0; j<4; ++j) {
            int value = INT_MIN;
            for(int k=0; k<3; ++k) {
                if(j!=k) value = max(value, points[i][k]+dp[i-1][k]);
            }
            dp[i][j] = value;
        }
    }
    return dp[n-1][3];
}


// Memoization - Top Down approach
// Time O(n)
// Space - O(n*4) + Function call stack O(n)
// n th day, n th day task m
int solve(int n, int m, vector<vector<int>> &pt, vector<vector<int>> &dp) {
    if(n==0) return pt[0][m];
    if(dp[n][m]!=-1) return dp[n][m];
    int value;
    if(m==0) value = max(solve(n-1, 1, pt, dp), solve(n-1, 2, pt, dp));
    else if(m==1) value = max(solve(n-1, 0, pt, dp), solve(n-1, 2, pt, dp));
    else if(m==2) value = max(solve(n-1, 0, pt, dp), solve(n-1, 1, pt, dp));
    return dp[n][m] = value + pt[n][m];
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    int value = INT_MIN;
    for(int i=0; i<3; ++i) {
        vector<vector<int>> dp(n, vector<int>(3, -1));
        value = max(value, solve(n-1, i, points, dp));
    }
    return value;
}

// Memoization - Top Down approach
// Time O(n)
// Space - O(n*4) + Function call stack O(n)
// index day, index+1 day task last
int solve(int index, int last, vector<vector<int>> &pt, vector<vector<int>> &dp) {
    
    if(dp[index][last]!=-1) return dp[index][last];
    
    if(index==0) {
        int value = INT_MIN;
        for(int i=0; i<3; ++i) {
            if(i!=last) value = max(value, pt[0][i]);
        }
        return dp[index][last] = value;
    }
    
    int maxValue = INT_MIN;
    for(int i=0; i<3; ++i) {
        if(i!=last) {
            int value = pt[index][i] + solve(index-1, i, pt, dp);
            maxValue = max(value, maxValue);
        }
    }
    return dp[index][last] = maxValue;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n-1, 3, points, dp);
}