// Best time to buy and sell stocks II -- leetcode 122
// Unlimited transaction
// But can hold only one stock
// Time complexity O(n)
// Space complexity O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    for(int i=1; i<n; ++i) {
        if(prices[i-1]<prices[i]) {
            maxProfit += (prices[i] - prices[i-1]);
        }
    }
    return maxProfit;
}