class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 0, count = 0;
        unordered_map<int, int>sumMap;
        
        for(int i=0; i<n; ++i) {
            
            curr += nums[i];
            
            if(curr==k)
                ++count;
            
            if(sumMap.find(curr-k)!=sumMap.end()) {
                count += sumMap[curr-k];
            }
            
            sumMap[curr]++;
        }
        
        return count;
    }
};