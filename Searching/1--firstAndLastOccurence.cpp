// https://techiedelight.com/practice/?id=5ql1
// leetcode 34

/*

Given a sorted integer array, find the index of a given number's first and last occurrence.

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 5
Output: (1, 3)
Explanation: The first and last occurrence of element 5 is located at index 1 and 3, respectively.

• If the target is not present in the array, the solution should return the pair (-1, -1).

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 4
Output: (-1, -1)

*/


// STL used

class Solution
{
public:
	pair<int,int> findPair(vector<int> const &nums, int target)
	{
		// Write your code here...
		int n = nums.size();
		int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		
		// target is not present in nums vector
		if(first==n or nums[first]!=target) {
			return {-1, -1};
		}
		
		int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
		
		return {first, last-1};
	}
};




// no STL used

class Solution {
public:
    
    int first(vector<int> &arr, int lo, int hi, int key) {
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<key) {
                lo = mid+1;
            }
            else if(arr[mid]>key) {
                hi = mid-1;
            }
            else {
                if(mid==0 or (arr[mid]!=arr[mid-1])) {
                    return mid;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
    
    int last(vector<int> &arr, int lo, int hi, int key, int n) {
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<key) {
                lo = mid+1;
            }
            else if(arr[mid]>key) {
                hi = mid-1;
            }
            else {
                if(mid==(n-1) or (arr[mid]!=arr[mid+1])) {
                    return mid;
                }
                else {
                    lo = mid+1;
                }
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            return {-1, -1};
        }
        int firstOccr = first(nums, 0, nums.size()-1, target);
        if(firstOccr==-1) {
            return {-1, -1};
        }
        int lastOccr = last(nums, 0, nums.size()-1, target, nums.size());
        return {firstOccr, lastOccr};
    }
};