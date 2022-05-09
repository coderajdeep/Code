// leetcode 81
// 

class Solution {
public:
    
    int searchUtil(vector<int> &arr, int target) {
        int lo = 0;
        int hi = arr.size()-1;
        
        while(lo<=hi) {
            
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]==target) {
                if(mid==0 or arr[mid]!=arr[mid-1]) {
                    return mid;
                }
                else {
                    hi = mid-1;
                }
            }
            
            else if(arr[lo]==arr[mid] and arr[mid]==arr[hi]) {
                ++lo;
                --hi;
            }
            
            // left half is sorted
            else if(arr[lo]<=arr[mid]) {
                if(target>=arr[lo] and target<arr[mid]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            // right part is sorted
            else {
                if(target>arr[mid] and target<=arr[hi]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
    
    bool search(vector<int>& nums, int target) {
        
        int ans = searchUtil(nums, target);
        
        //cout<<ans<<"\n";
        
        if(ans!=-1)
            return true;
        
        return false;
    }
};