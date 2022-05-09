class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        int curr = 0, maxLen = 0;
        
        unordered_map<int, int> sumMap;
        
        for(int i=0; i<N; ++i) {
            
            curr += A[i];
            
            if(curr==K) {
                maxLen = i+1;
            }

            // if(sumMap.find(curr)==sumMap.end()) {
            //     sumMap[curr] = i;
            // }
            
            
            if(sumMap.find(curr-K)!=sumMap.end()) {
                int val = sumMap[curr-K];
                int len = i - val;
                if(maxLen<len) {
                    maxLen = len;
                }
            }

            // This if condition is required
            if(sumMap.find(curr)==sumMap.end()) {
                sumMap[curr] = i;
            }
            // Can I sift this if block middle of other two if block
        }
        
        return maxLen;
    } 

};