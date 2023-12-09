// Maximum consecutive one 
// leetcode 485

// Best approach
// Time complexity O(n)
// Space complexity O(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int count = 0, maxCount = 0;
    for(int i=0; i<n; ++i) {
        if(nums[i]==0) {
            maxCount = max(maxCount, count);
            count = 0;
        }
        else {
            ++count;
        }
    }
    maxCount = max(maxCount, count);
    return maxCount;
}