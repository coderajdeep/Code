// Longest subarray with given sum
// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// https://www.codingninjas.com/studio/problems/920321

// Brute force approach
// Time complexity O(n^2)
// Space complexity O(1)
int lenOfLongSubarr(int A[],  int N, int K) { 
    int maxLen = 0;
    for(int i=0; i<N; ++i) {
        int sum = 0;
        for(int j=i; j<N; ++j) {
            sum += A[j];
            if(sum==K) {
                maxLen = max(maxLen, (j-i+1));
            }
        }
    }
    return maxLen;
}

// Time complexity O(n)
// Space complexity O(n)
int lenOfLongSubarr(int A[],  int N, int K) { 
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLen = 0;
    for(int i=0; i<N; ++i) {
        sum += A[i];
        if(sum==K) {
            maxLen = i + 1;
        }
        if(prefixSum.find(sum)==prefixSum.end()) {
            prefixSum[sum] = i;
        }
        auto it = prefixSum.find(sum - K);
        if(it!=prefixSum.end()) {
            maxLen = max(maxLen, (i - it->second));
        }
    }
    return maxLen;
}

// Same as previous
// Just handling the case where 0 to i index is giving max length subarray
int lenOfLongSubarr(int A[],  int N, int K) { 
    unordered_map<int, int> prefixSum;
    prefixSum[0] = -1;
    int sum = 0, maxLen = 0;
    for(int i=0; i<N; ++i) {
        sum += A[i];
        if(prefixSum.find(sum)==prefixSum.end()) {
            prefixSum[sum] = i;
        }
        auto it = prefixSum.find(sum - K);
        if(it!=prefixSum.end()) {
            maxLen = max(maxLen, (i - it->second));
        }
    }
    return maxLen;
}