// Longest subarray with given sum
// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
// When Array elements are non-negative
// Time complexity O(n)
// Space complexity O(1)

// [1 1 1 1 .. upto 10^6 100000000] and k = 100000000
// For this test case, time complexity will be O(n^2)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = 0;
    int index = 0, leftIndex = 0, n = a.size(), maxLength = 0;
    while(index<n) {
        sum += a[index];
        while(leftIndex<=index && sum>k) {
            sum -= a[leftIndex];
            ++leftIndex;
        }
        if(sum==k) {
            maxLength = max(maxLength, index - leftIndex + 1);
        }
        ++index;
    }
    return maxLength;
}

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
            else if(sum>K) {
                break;
            }
        }
    }
    return maxLen;
}

// When Array elements are non-negative
// Time complexity O(n)
// Space complexity O(1)
int longestSubarrayWithSumK(vector<int>& a, long long k) {
    long long n = a.size(), startIndex = 0, index = 0, maxLen = 0, sum = 0;
    while(index<n) {
        sum += a[index];
        while(startIndex<=index && sum>k) {
            sum -= a[startIndex++];
        }
        if(sum == k) {
            maxLen = max(maxLen, index-startIndex+1);
        }
        ++index;
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
        auto it = prefixSum.find(sum - K);
        if(it!=prefixSum.end()) {
            maxLen = max(maxLen, (i - it->second));
        }
        // This is ensuring that the prefix having the earliest index 
        // So we can get the max length subarray
        if(prefixSum.find(sum)==prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}

// https://www.codingninjas.com/studio/problems/920321
// Max length sumarray with zero sum
// Time complexity O(n)
// Space complexity O(n)
int LongestSubsetWithZeroSum(vector<int> arr) {
    int n = arr.size();
    int sum = 0, maxLen = 0;
    unordered_map<int, int> prefixSum;
    prefixSum[0] = -1;
    for(int i=0; i<n; ++i) {
        sum += arr[i];
        auto it = prefixSum.find(sum);
        if(it!=prefixSum.end()) {
            maxLen = max(maxLen, (i - it->second));
        }
        else {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}