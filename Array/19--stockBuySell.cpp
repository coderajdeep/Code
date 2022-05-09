// Type 1
// leetcode 121
// If only one transaction is allowed
// then it will be similar of 16 no problem

// if we want to print buy and sell day you can get this

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) {
            return 0;
        }
        
        int minPrice = prices[0], profit = 0;
        int buy = 0, sell = -1;
        
        for(int i=1; i<n; ++i) {
            
            if(minPrice<prices[i]) {
                profit = max(profit, prices[i]-minPrice);
                sell = i;
            }
            
            // minPrice = min(minPrice, prices[i]);
            if(minPrice > prices[i]) {
                minPrice = prices[i];
                buy = i;
            }
        }
        
        return profit;
    }
    
    // int maxProfit(vector<int>& prices) {
    //     int minPrice = prices[0], buy = 0, sell = -1, n = prices.size(), profit = 0;
    //     for(int i=1; i<n; ++i) {
    //         if(minPrice < prices[i]) {
    //             profit = max(profit , prices[i] - minPrice);
    //             sell = i;
    //         }
    //         else {
    //             minPrice = prices[i];
    //             buy = i;
    //         }
    //     }
    //     return profit;
    // }
};




// Type 2
// leetcode 122
// Unlimited number of transaction

// This will give the only profit

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n==1) 
            return 0;
        
        int profit = 0;
        
        for(int i=1; i<n; ++i) {
            if(prices[i-1]<prices[i]) {
                profit += (prices[i] - prices[i-1]);
            }
        }
        
        return profit;
    }
};

// This will print when buy and when sell
// Geeks Problem

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        if(n<=1)
            return {};
        int buy = -1, sell = -1;
        
        if(A[0]<A[1]) {
            buy = 0;
        }
        
        vector<vector<int>>ans;
        
        for(int i=1; i<(n-1); ++i) {
            
            if(A[i]>A[i-1] and A[i]>=A[i+1]) {
                sell = i;
                ans.push_back({buy, sell});
            }
            
            else if(A[i]<=A[i-1] and A[i]<A[i+1]) {
                buy = i;
            }
        }
        
        if(A[n-2]<A[n-1]) {
            ans.push_back({buy, n-1});
        }
        return ans;
    }
};



// Type 3
// Infinite buy-sell buy and transaction fee on each sell
// Leetcode 714
// peepcoding tutorial
// https://youtu.be/MyqDgMy-Kew

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<=1)
            return 0;
        int prevBuy = -prices[0], prevSell = 0;
        int currBuy = 0, currSell = 0;
        
        for(int i=1; i<n; ++i) {
            
            if( (prevSell- prices[i]) > prevBuy) {
                currBuy = prevSell - prices[i];    
            }
            else {
                currBuy = prevBuy;
            }
            
            if((prevBuy + prices[i] - fee) > prevSell) {
                currSell = prevBuy + prices[i] - fee;
            }
            else {
                currSell = prevSell;
            }
            
            prevSell = currSell;
            prevBuy = currBuy;
        }
        
        return currSell;
    }
};




// Type 4
// There can be atmost k transaction (leetcode 188)
// https://youtu.be/3YILP-PdEJA
// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
// This solution can be optimized

class Solution {
  public:
    int maxProfit(int k, int n, int arr[]) {
        // code here
        int profit[k+1][n];
        
        // profit in 0th day (1st Day) will be always zero
        for(int t=0; t<=k; ++t) {
            profit[t][0] = 0;
        }
        
        for(int d=0; d<n; ++d) {
            profit[0][d] = 0;
        }
        
        for(int t=1; t<=k; ++t) {
            
            for(int d=1; d<n; ++d) {
                
                int value = INT_MIN;
                
                for(int i=0; i<d; ++i) {
                    value = max(value, profit[t-1][i] + arr[d] - arr[i]);
                }
                
                profit[t][d] = max( profit[t][d-1] , value);
                
            }
        }
        
        return profit[k][n-1];
    }
};


// Optimized version (leetcode)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n<=1)
            return 0;
        
        int dp[k+1][n];
        
        // 0-th day profit will be zero
        for(int t=0; t<=k; ++t) {
            dp[t][0] = 0;
        }
        
        // if transaction is 0 then profit will be also 0
        for(int d=0; d<n; ++d) {
            dp[0][d] = 0;
        }
        
        for(int t=1; t<=k; ++t) {
            
            int value = INT_MIN;
            
            for(int d=1; d<n; ++d) {
                
                value = max(value, dp[t-1][d-1] - prices[d-1]);
                
                // for(int day=0; day<d; ++day) {
                //     value = max(value, dp[t-1][day] + prices[d] - prices[day]);
                // }
                
                dp[t][d] = max(dp[t][d-1], value + prices[d]);
            }
        }
        
        return dp[k][n-1];
    }
};