/*

Given an integer array, find all contiguous subarrays with a given sum `k`.

Input : nums[] = [3, 4, -7, 1, 3, 3, 1, -4], k = 7
Output: {[3, 4], [3, 4, -7, 1, 3, 3], [1, 3, 3], [3, 3, 1]}

Since the input can have multiple subarrays with sum `k`, the solution should return a set containing all the distinct subarrays.

*/

class Solution
{
public:
	set<vector<int>> getAllSubarrays(vector<int> const &nums, int k)
	{
		set<vector<int>> subarrays;

		// Write your code here...
		
		int n = nums.size(), curr = 0;
		
		unordered_map<int, vector<int>> sumMap;
		
		sumMap[0].push_back(-1);
		
		for(int i=0; i<n; ++i) {
			
			curr += nums[i];
			
			auto it = sumMap.find(curr-k);
			
			if(it!=sumMap.end()) {
				for(int start:it->second) {
					vector<int>temp(nums.begin()+start+1, nums.begin()+i+1);
					subarrays.insert(temp);
				}
			}
			sumMap[curr].push_back(i);
		}

		return subarrays;
	}
};

// https://techiedelight.com/practice/?id=cB2v
// Time complexity - O(n2)
// Space complexity - O(n)