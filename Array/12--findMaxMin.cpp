/*

Given a non-empty integer array, find the minimum and maximum element in the array by making minimum comparisons, and return the (min, max) element pair.

Input: [5, 7, 2, 4, 9, 6]
Output: (2, 9)

Explanation:

The minimum array element is 2
The maximum array element is 9

https://techiedelight.com/practice/?id=k09O

*/

class Solution
{
public:

	pair<int, int> solve(vector<int> const &arr, int n) {
		
		if(n==0) {
			return {INT_MAX, INT_MIN};
		}
		
		return {min(arr[n-1], solve(arr, n-1).first), max(arr[n-1], solve(arr, n-1).second)};
	}
	
	pair<int,int> findMinAndMax(vector<int> const &nums)
	{
		// Write your code here...
		
		int n = nums.size();
		
		return solve(nums, n);
	}
};
