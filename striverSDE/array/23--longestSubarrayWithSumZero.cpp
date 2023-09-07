// Longest subarray with given sum (here given sum is zero)
// https://www.codingninjas.com/studio/problems/920321

int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int maxLength = 0, length;
    for(int i=0; i<n; ++i) {
      int sum = 0;
      for(int j=i; j<n; ++j) {
        sum += arr[j];
        if(sum==0) {
          length = (j - i + 1);
          maxLength = max(maxLength, length);
        }
      }
    }
    return maxLength;
}