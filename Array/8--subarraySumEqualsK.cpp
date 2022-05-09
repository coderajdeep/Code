// Is there any subarray exist which has sum equals to s
// return index of the subarray
// This code valid for non-negative numbers
// we are doing this for for handling zero and positive numbers

class Solution {
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        long long curr = arr[0];
        
        int start = 0;
        
        for(int i=1; i<=n; ++i) {
            while(curr>s && start<(i-1)) {
                curr = curr - arr[start];
                ++start;
            }
            if(curr==s) {
                return {start, i-1};
            }
            if(i<n) {
                curr += arr[i];
            }
        }
        return {-1};
    }
};


// Constant space
// https://www.geeksforgeeks.org/find-subarray-with-given-sum-with-negatives-allowed-in-constant-space/