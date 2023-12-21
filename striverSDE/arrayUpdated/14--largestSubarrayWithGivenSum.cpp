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

// Generate all subarray with given sum
vector<pair<int, int>> getAllSubarrayWithGivenSum(vector<int>& nums, int k) {
    int n = nums.size(), prefixSum = 0;
    unordered_map<int, vector<int>> umap;
    vector<pair<int, int>> ans;
    umap[0].push_back(-1);
    for (int i = 0; i < n; ++i) {
        prefixSum += nums[i];
        auto it = umap.find(prefixSum - k);
        if (it != umap.end()) {
            for (auto itr = it->second.begin(); itr != it->second.end(); ++itr) {
                ans.push_back(pair<int, int>{*itr+1, i});
            }
        }
        umap[prefixSum].push_back(i);
    }
    return ans;
}

vector<pair<int, int>> getAllSubarrayWithGivenSumBruteFource(vector<int>& nums, int k) {
    int n = nums.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == k) {
                ans.push_back(pair<int, int>{i, j});
            }
        }
    }
    return ans;
}