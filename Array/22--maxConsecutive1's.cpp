// leetcode 485

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0, curr = 0;
        
        for(int i=0; i<n; ++i) {
            if(nums[i]==1) {
                ++curr;
                count = max(count, curr);
            }
            else {
                curr = 0;
            }
        }
        return count;
    }
};