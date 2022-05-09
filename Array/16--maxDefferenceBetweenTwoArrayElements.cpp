/*

2016. Maximum Difference Between Increasing Elements

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

*/


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minValue = nums[0];
        int ans = -1;
        
        for(int i=1; i<n; ++i) {
            if(minValue<nums[i]) {
                ans = max(ans, (nums[i]-minValue));
            }
            minValue = min(minValue, nums[i]);
        }
        
        return ans;
    }
};