// Max point you can obtain from cards -- leetcode 1423

// Time complexity O(k)
// Time complexity O(1)
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int low = 1, high = n - k, sum = 0, ans = 0;
    for(int i=1; i<=k; ++i) {
        sum += cardPoints[n-i];
    }
    if(n == k) return sum;
    ans = sum;
    while(high < n) {
        sum += (cardPoints[low-1]-cardPoints[high]);
        ans = max(ans, sum);
        ++low;
        ++high;
    }
    return ans;
}