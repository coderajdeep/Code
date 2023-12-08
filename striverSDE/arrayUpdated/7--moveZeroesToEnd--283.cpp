// Move All Zero to the end of the array -- leetcode 283
// Time complexity O(2*n)
// Space complexity O(n)
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    int temp[n];
    for(int i=0; i<n; ++i) {
        if(nums[i]) {
            temp[index++] = nums[i];
        }
    }
    for(int i=0; i<index; ++i) {
        nums[i] = temp[i];
    }
    for(int i=index; i<n; ++i) {
        nums[i] = 0;
    }
}

// Time complexity O(2*n)
// When all of the elements are zero then we need two complete traversal
// Space complexity O(1)
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    for(int i=0; i<n; ++i) {
        if(nums[i]) {
            nums[index++] = nums[i];
        }
    }
    for(int i=index; i<n; ++i) {
        nums[i] = 0;
    }
    
}