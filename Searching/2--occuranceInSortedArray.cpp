// https://techiedelight.com/practice/?id=_a67

/*

Given a sorted integer array containing duplicates, return the count of occurrences of a given number.

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 5
Output: 3
Explanation: Target 5 occurs 3 times

Input: nums[] = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 6
Output: 2
Explanation: Target 6 occurs 2 times

Input: nums[] = [5, 4, 3, 2, 1], target = 6
Output: 0
Explanation: Target 6 occurs 0 times

*/

class Solution
{
public:

	int lowerBound(vector<int> const &arr, int lo, int hi, int key) {
		
		while(lo<hi) {
			
			int mid = lo + (hi-lo)/2;
			
			if(key<=arr[mid]) {
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}
		
		if(lo<arr.size() and arr[lo]<key) {
			++lo;
		}
		
		return lo;
	}
	
	int upperBound(vector<int> const &arr, int lo, int hi, int key) {
		
		while(lo<hi) {
			
			int mid = lo + (hi-lo)/2;
			
			if(key<arr[mid]) {
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}
		
		if(lo<arr.size() and arr[lo]<=key) {
			++lo;
		}
		
		return lo;
	}
	
	int countOccurrences(vector<int> const &nums, int target)
	{
		// Write your code here...
		
		int n = nums.size();
		
		if(n==0) {
			return 0;
		}
		
		int lower = lowerBound(nums, 0, n-1, target);
		int upper = upperBound(nums, 0, n-1, target);
		
		return (upper-lower);
	}
};
