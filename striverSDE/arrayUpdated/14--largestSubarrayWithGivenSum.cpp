// Time complexity O(n)
// Space complexity O(n)

int getLongestSubarray(vector<int>& nums, int k){
    int sum = 0, maxLen = 0, n = nums.size();
    unordered_map<int, int> um;
    um[0] = -1;
    for(int i=0; i<n; ++i) {
        sum += nums[i];
        if(um.find(sum)==um.end()) {
            um[sum] = i;
        }
        auto it = um.find(sum-k);
        if(it!=um.end()) {
            maxLen = max(maxLen, (i-it->second));
        }
    }
    return maxLen;
}