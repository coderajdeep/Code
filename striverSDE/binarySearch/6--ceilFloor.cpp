// Find ceil and floor of a number in array

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n);
	auto lower = lower_bound(arr, arr + n, x);
	int lowerIndex = lower - arr;
	if(lowerIndex==n) {
		return {arr[n-1], -1};
	}
	else if(lowerIndex==0) {
		return {-1, arr[0]};
	}
	else if(arr[lowerIndex]==x) {
		return {x, x};
	}
	else {
		return {arr[lowerIndex-1], arr[lowerIndex]};
	}
}