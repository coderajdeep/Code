// Koko eating bananas -- leetcode 875

// Time complexity O(log(max num in array) + (max num in array))
// Space complexity O(1)
int getMaxValue(vector<int>& piles) {
    int maxElement = INT_MIN;
    for(int val:piles) {
        maxElement = max(maxElement, val);
    }
    return maxElement;
}
long totalTimeRequired(vector<int>& piles, int k) {
    long total = 0;
    for(int val:piles) {
        total += ceil((double)val/k);
    }
    return total;
}
int minEatingSpeed(vector<int>& piles, int h) {
    long maxVal = getMaxValue(piles);
    long low = 1, high = maxVal, mid, k;
    while(low <= high) {
        mid = low + (high - low) / 2;
        long timeRequired = totalTimeRequired(piles, mid);
        if(timeRequired <= (long)h) {
            k = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return k;
}