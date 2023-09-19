// Single element in sorted array - leetcode 540

// Time complexity O(logn)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-2]!=nums[n-1]) return nums[n-1];
    // Now we can say that the single element can't be on first or last index
    int low = 1, high = n-2, mid;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]) {
            return nums[mid];
        }
        if(mid%2==1) {
            if(nums[mid]==nums[mid-1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            if(nums[mid]==nums[mid+1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}