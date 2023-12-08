// Missing Number in ana array -- leetcode 268

// Time complexity O(n)
// Space complexity O(1)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans = (ans^nums[i]^(i+1));
    }
    return ans;
}