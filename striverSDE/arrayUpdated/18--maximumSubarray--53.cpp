// Maximum subarray sum - Kadane's Algorithm -- leetcode 53

// Time complexity O(n)
// Space complexity O(1)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    // This is for tracking ovarall maximum value
    int maxValue = nums[0];
    // This is for tracking current maximum value
    int currMax = nums[0];
    for(int i=1; i<n; ++i) {
        // If the current number is greater than 
        // the value of current number + currentActive subarray
        // Then I will update the current maximum
        if(nums[i]<(nums[i]+currMax)) {
            currMax += nums[i];
        }
        else {
            currMax = nums[i];
        }
        if(maxValue<currMax) {
            maxValue = currMax;
        }
    }
    return maxValue;
}