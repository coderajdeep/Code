// Binary subarray with given sum -- leetcode 930

// Time complexity O(n)
// Space complexity O(n)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, ans = 0;
    for(int num : nums) {
        sum += num;
        auto it = prefixSum.find(sum -  goal);
        if(it != prefixSum.end()) {
            ans += it->second;
        }
        prefixSum[sum]++;
    }
    return ans;
}

// Best approach
// Time complexity O(n)
// Space complexity O(1)
long countSubarrayLessEqualSum(vector<int>& nums, int goal) {
    if(goal < 0) return 0;
    int low = 0, high = 0, n = nums.size();
    long count = 0, sum = 0;
    while(high < n) {
        sum += nums[high];
        while(low<=high && sum>goal) {
            sum -= nums[low++];
        }
        // total subarray having sum <= goal between [low , high] 
        // minus
        // total subarray having sum <= goal between [low , high-1]
        // equals
        // (high - low + 1)
        count += (high - low + 1);
        ++high;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return countSubarrayLessEqualSum(nums, goal) - countSubarrayLessEqualSum(nums, goal-1);
}