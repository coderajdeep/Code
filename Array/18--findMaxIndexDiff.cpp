class Solution {
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        
        int lmin[N], rmax[N];
        
        lmin[0] = A[0];
        rmax[N-1] = A[N-1];
        
        int i = 1, j = N-2;
        
        while(i<N and j>=0) {
            lmin[i] = min(lmin[i-1], A[i]);
            rmax[j] = max(rmax[j+1], A[j]);
            ++i;
            --j;
        }
        
        int maxDiff = -1;
        i = 0;
        j = 0;
        
        while(i<N and j<N) {
            if(lmin[i]<=rmax[j]) {
                maxDiff = max(maxDiff, (j-i));
                ++j;
            }
            else {
                ++i;
            }
        }
        
        return maxDiff;
    }
};