
// Leetcode 1004
// Max consecutive one after atmost k fiipped of zero to one in binary array
// This can be simplified
// https://youtu.be/QPfalDbqa4A


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int zero = 0, start = 0, end = 0, ans = 0;
        
        for(int i=0; i<n; ++i) {
            
            if(nums[i]==0) {
                ++zero;
                end = i;
            }
            
            if(zero<=k) {
                end = i;
                ans = max(ans, end - start +1);
            }
            
            else {
                while(zero>k) {
                    if(nums[start]==0) {
                        --zero;
                    }
                    ++start;
                }
            }
        }
        
        return ans;
    }
};