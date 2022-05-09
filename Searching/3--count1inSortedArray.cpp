// https://techiedelight.com/practice/?id=Hqr8

/*

Given a sorted binary array, efficiently count the total number of 1's in it.

Input: [0, 0, 0, 0, 1, 1, 1]
Output: 3

Input: [0, 0, 1, 1, 1, 1, 1]
Output: 5

*/

// We can solve this by finding 1's firts occurence

class Solution
{
public:

	int solve(vector<int> const &arr, int lo, int hi) {
		
		if(lo>hi) {
			return 0;
		}
		
		if(arr[hi]==0) {
			return 0;
		}
		if(arr[lo]==1) {
			return (hi-lo+1);
		}
		int mid = lo + (hi-lo)/2;
		
		return solve(arr, lo, mid) + solve(arr, mid+1, hi);
	}
	
	int countOnes(vector<int> const &nums)
	{
		// Write your code here...
		int n = nums.size();
		if(n==0) {
			return 0;
		}
		int count = solve(nums, 0, n-1);
		return count;
	}
};
