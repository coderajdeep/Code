// Leetcode 213
// House Robber II

// leetcode solution
// Space optimized Bottom up approach - tabulation
// Time O(n)
// Space O(1)
// Edge case, n==1 and n==2
class Solution {
public:
    // solve function will work when st<end
    int solve(vector<int> &nums, int st, int end) {
        int prev2 = nums[st];
        int prev1 = max(nums[st], nums[st+1]);
        int curr = prev1;
        for(int i=st+2; i<=end; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0], nums[1]);
        int exculdeLast = solve(nums, 0, n-2);
        int excludeFirst = solve(nums, 1, n-1);
        return max(excludeFirst, exculdeLast);
    }
};