/*

Given a circularly sorted array of distinct integers, find the total number of times the array is rotated. You may assume that the rotation is in anti-clockwise direction.

Input: [8, 9, 10, 2, 5, 6]
Output: 3

Input: [2, 5, 6, 8, 9, 10]
Output: 0

*/

// leetcode 153
// https://techiedelight.com/practice/?id=lCV3

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        
        while(lo<=hi) {
            if(nums[lo]<=nums[hi]) {
                return nums[lo];
            }
            
            int mid = lo + (hi-lo)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(nums[mid]<=nums[prev] and nums[mid]<=nums[next]) {
                return nums[mid];
            }
            
            if(nums[lo]<=nums[mid]) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return -1;
    }
};