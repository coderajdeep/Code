// (We can't check if an array is sorted or not in logN complexity)

int isSorted(int n, vector<int> a) {
    if(n<=1) return 1;
    for(int i=1; i<n; ++i) {
        if(a[i]<a[i-1]) return 0;
    }
    return 1;
}
