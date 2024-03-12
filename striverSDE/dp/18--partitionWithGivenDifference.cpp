// Count Partition with given difference -- coding ninjas
// Time complexity O(n*(sum-d)/2)
// Space complexity O((sum-d)/2)
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i=0; i<n; ++i) sum += arr[i];
    int target = (sum - d);
    if((target & 1) || target < 0) return 0;
    target /= 2;
    int prev[target+1] = {0};
    int curr[target+1];
    const int mod = 1e9+7;
    prev[0] = 1;
    if(arr[0]==0) prev[0] = 2;
    else if(arr[0] <= target) prev[arr[0]] = 1;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=target; ++j) {
            int pick = (arr[i]<=j) ? prev[j-arr[i]] : 0;
            int notPick = prev[j];
            curr[j] = (pick + notPick)%mod;
        }
        for(int j=0; j<=target; ++j) prev[j] = curr[j];
    }
    return prev[target];
}