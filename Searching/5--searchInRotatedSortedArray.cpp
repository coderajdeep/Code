// leetcode 33
// No duplicate is allowed
// https://techiedelight.com/practice/?id=qIMZ

/*

Given a circularly sorted integer array, search a target element in it. If the target exists in the array, the procedure should return the index of it. If the target is not located, the procedure should return -1. You may assume there are no duplicates in the array, and the rotation is in the anti-clockwise direction.

Input: nums[] = [8, 9, 10, 2, 5, 6], target = 10
Output: 2
Explanation: Element found at 3rd (index 2) position.

Input: nums[] = [9, 10, 2, 5, 6, 8], target = 5
Output: 3
Explanation: Element found at 4th (index 3) position.

Input: nums[] = [8, 9, 1, 4, 5], target = 2
Output: -1
Explanation: Target not found

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int lo = 0, hi = nums.size()-1;
        
        // one of the half will be always sorted
        while(lo<=hi) {
            
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid]==target) {
                return mid;
            }
            
            // left half is sorted
            // <= is important
            // if we only use < then [3, 1] - target = 1 will not pass
            if(nums[lo]<=nums[mid]) {
                if(target>=nums[lo] and target<nums[mid]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            
            // else right half is sorted
            else {
                if(target>nums[mid] and target<=nums[hi]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        
        return -1;
    }
};