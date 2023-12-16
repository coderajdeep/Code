// Longest Consecutive Sequence -- leetcode 128

// Array cabn be empty and array can have duplicate numbers
// Time complexity O(nlogn)
// Space complexity O(1)
int longestConsecutive(vector<int>& nums) {
    int n = nums.size(), lastSmallest = INT_MIN, count, maxCount = INT_MIN;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; ++i) {
        if(lastSmallest+1 == nums[i]) {
            ++count;
        }
        else if(lastSmallest != nums[i]){
            count = 1;
        }
        lastSmallest = nums[i];
        maxCount = max(count, maxCount);
    }
    return maxCount == INT_MIN ? 0 : maxCount;
}


// Time complexity O(n)
// Space complexity O(n)
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n<=1) return n;
    unordered_set<int> us;
    for(int i=0; i<n; ++i) {
        us.insert(nums[i]);
    }
    int count, maxCount = 1;
    for(auto it=us.begin(); it!=us.end(); ++it) {
        int curr = *it;
        int prev = curr - 1;
        if(us.find(prev)==us.end()) {
            count = 1;
            int next = curr + 1;
            while(true) {
                if(us.find(next)==us.end()) {
                    maxCount = max(maxCount, count);
                    break;
                }
                else {
                    ++next;
                    ++count;
                }
            }
        }
    }
    return maxCount;
}