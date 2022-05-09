// Optimized approach using deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.empty() || (k>n))
            return {};
        deque<int>q;
        vector<int>ans(n-k+1);
        int index = 0;
        
        for(int i=0; i<k; ++i) {
            while(!q.empty() and nums[q.back()]<=nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        ans[index] = nums[q.front()];
        
        for(int i=k; i<n; ++i) {
            // Checking the front element is in the current window or not
            // if not then remove the front elemet
            if(!q.empty() and (i-k)>=q.front())
                q.pop_front();
            
            while(!q.empty() and nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
            
            ans[++index] = nums[q.front()];
        }
        
        return ans;
    }
};



// Brute fource
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        if(k>n)
            return {};
            
        vector<int>ans(n-k+1);
        
        for(int i=0; i<(n-k+1); ++i) {
            int val = arr[i];
            for(int j=i+1; j<(i+k); ++j) {
                val = max(val, arr[j]);
            }
            ans[i] = val;
        }
        return ans;
    }
};