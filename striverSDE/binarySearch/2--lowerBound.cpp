// Implement lower bound for non decreasing array - coding ninja
// https://www.codingninjas.com/studio/problems/lower-bound_8165382

// Time complexity O(logn)
// Space complexity O(1)
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n, mid;
	if(x<arr[0]) {
		low = 0;
	}
	else if(x>arr[n-1]) {
		low = n;
	}
	else {
		while(low<high) {
			mid = low + (high - low) / 2;
			if(x <= arr[mid]) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return low;
}