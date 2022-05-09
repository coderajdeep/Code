// leetcode 15
// What happen when we need to maintain order of element and need to maintain duplicates

// my solution
// my solution using set is in leetcode submission
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n<=2) {
            return vector<vector<int>>{}; // same as {}
        }
        
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        
        for(int i=0; i<n-2; ++i) {
            
            if(i>0 and nums[i-1]==nums[i]) {
                continue;
            }
            
            int lo = i+1;
            int hi = n-1;
            
            while(lo<hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if(sum>0) {
                    --hi;
                }
                else if(sum<0) {
                    ++lo;
                }
                else {
                    
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    
                    while((lo+1)<n and (nums[lo]==nums[lo+1])) {
                        ++lo;
                    }
                    while((hi-1)>=0 and (nums[hi]==nums[hi-1])) {
                        --hi;
                    }
                    ++lo;
                    --hi;
                }
            }
        }
        return ans;
    }
};


// leetcode discussion
vector<vector<int>> threeSum(vector<int>& nums) {
 
    sort(nums.begin(), nums.end());
    
    // two pointer: fix one pointer
    // sum > 0; r-- else l++
    
    vector<vector<int>> res;
    int n = nums.size();
    
    if(n<3) return res;
    
    for(int i=0; i<n-2; i++) {
        
        int l=i+1, r=n-1;
        
        // skip duplicates for ith index
        if(i!=0  && nums[i]==nums[i-1]) continue;
        
        while(l<r) {

            int target = nums[l] + nums[r] + nums[i];
            
            if(target == 0) {
                res.push_back( {nums[i], nums[l], nums[r]} );
            
            // why ? // skip duplicate pairs 
            // brings the pointer to the last occurence of a repeated number in nums
            while(r-1>=l && nums[r-1]==nums[r]) r--;
            while(l+1<r && nums[l+1]==nums[l] ) l++;
             
                // since we have skipped duplicates and are on the last occurence of the duplicate we need to update the pointers
                l++;
                r--;                    
            }
            
            else if(target>0) 
                 r--;    // reduce the target
            else
                 l++;

        }
    }
    
    return res;
}