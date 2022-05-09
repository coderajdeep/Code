
// Time O(n) Space O(1)
// One traversal

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currIndex = 0;
        int n = nums.size();
        
        for(int i=0; i<n; ++i) {
            if(nums[i]!=0) {
                swap(nums[i], nums[currIndex++]);
            }
        }
    }
};

// Time O(n) Space O(1)
// Two traversal

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currIndex = 0;
        int n = nums.size();
        
        for(int i=0; i<n; ++i) {
            if(nums[i]!=0) {
                nums[currIndex++] = nums[i];
            }
        }
        
        for(int i=currIndex; i<n; ++i) {
            nums[i] = 0;
        }
    }
};