// 3Sum
// Leetcode 15
// Time complexity O(n*n*log(n))
// Space complexity O(n)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    for(int i=0; i<n-2; ++i) {
        int start = i+1, end = n-1;
        while(start<end) {
            int sum = nums[i] + nums[start] + nums[end];
            if(sum == 0) {
                st.insert(vector<int> {nums[i], nums[start], nums[end]});
                ++start;
                --end;
            }
            else if(sum > 0) {
                --end;
            }
            else {
                ++start;
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}