// https://www.codingninjas.com/studio/problems/count-inversions_615
// Time complexity O(n^2)
// Space complexity O(1)
long long getInversions(long long *arr, int n){
    int count = 0;
    for(int i=0; i<n-1; ++i) {
        for(int j=i+1; j<n; ++j) {
            if(arr[i]>arr[j]) {
                ++count;
            }
        }
    }
    return count;
}

// Time complexity O(nlogn)
// Space complexity O(n)
int merge(int low, int mid, int high, long long *arr, long long *temp) {
    int cnt = 0;
    for(int i=low; i<=mid; ++i) {
        temp[i] = arr[i];
    }
    for(int i=mid+1; i<=high; ++i) {
        temp[i] = arr[i];
    }
    int index = low, i = low, j = mid+1;
    while(i<=mid && j<=high) {
        if(temp[i]<=temp[j]) {
            arr[index++] = temp[i++];
        }
        else {
            cnt += (mid - i + 1);
            arr[index++] = temp[j++];
        }
    }
    while(i<=mid) {
        arr[index++] = temp[i++];
    }
    while(j<=mid) {
        arr[index++] = temp[j++];
    }
    return cnt;
}
int mergeSort(int low, int high, long long *arr, long long *temp) {
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = (high-low)/2 + low;
    cnt += mergeSort(low, mid, arr, temp);
    cnt += mergeSort(mid+1, high, arr, temp);
    cnt += merge(low, mid, high, arr, temp);
    return cnt;
}
long long getInversions(long long *arr, int n){
    long long *temp = new long long[n];
    int ans = mergeSort(0, n-1, arr, temp);
    return ans;
}