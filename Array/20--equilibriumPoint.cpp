class Solution {
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        
        long long sum = 0, leftSum = 0;
        for(long long i=0; i<n; ++i) {
            sum += a[i];
        }
        
        for(long long i=0; i<n; ++i) {
            
            sum -= a[i];
            
            if(leftSum==sum) {
                return (i+1); // 1 based indexing
            }
            
            leftSum += a[i];
        }
        return -1;
    }

};