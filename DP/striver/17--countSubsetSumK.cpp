// Count subsets sum equals to K
// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
// https://techiedelight.com/practice/?problem=SubsetSumProblem

class Solution {
public:
	int solve(int index, int tar, vector<int> const &nums, vector<vector<int>> &dp) {
		if(tar==0) return 1;
		if(index==0) return (nums[0]==tar)?1:0;
		if(dp[index][tar]!=-1) return dp[index][tar];
		int pick = 0;
		if(nums[index]<=tar) pick = solve(index-1, tar-nums[index], nums, dp);
		int notPick = solve(index-1, tar, nums, dp);
		return dp[index][tar] = pick + notPick;
	}
	bool subsetSum(vector<int> const &nums, int k) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(k+1, -1));
		int ans = solve(n-1, k, nums, dp);
		return ans;
	}
};