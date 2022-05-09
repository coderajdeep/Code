// Space can be optimized

// Leetcode 41
// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

class Solution {
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        if(n==2) {
            return 0;
        }
        
        int left[n], right[n];
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        int i=1, j=n-2;
        
        while(i<n and j>=0) {
            
            left[i] = max(left[i-1], arr[i]);
            right[j] = max(right[j+1], arr[j]);
            
            ++i; --j;
        }
        
        long long ans = 0;
        
        for(int i=1; i<(n-1); ++i) {
            
            int value = (min(left[i-1], right[i+1]) - arr[i]);
            
            if(value>0) {
                ans += value;
            }
        }
        
        return ans;
    }
};