#include <iostream>
#include <vector>

using namespace std;

int totalSubsequenceWithGivenSum(int index, int n, int k, int sum, int *arr) {
	if(index==n) {
		if(sum==k) return 1;
		else return 0;
	}
	sum += arr[index];
	int l = totalSubsequenceWithGivenSum(index+1, n, k, sum, arr);
	sum -= arr[index];
	int r = totalSubsequenceWithGivenSum(index+1, n, k, sum, arr);
	return (l+r);
}

int solve(int index, int n, int sum, int *arr) {
	if(index==n) {
		if(sum==0) return 1;
		else return 0;
	}
	int in = solve(index+1, n, sum-arr[index], arr);
	int ex = solve(index+1, n, sum, arr);
	return (in+ex);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n, k, K, sum = 0;
		cin>>n>>k;
		K = k;
		int arr[n];
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}
		cout<<totalSubsequenceWithGivenSum(0, n, k, sum, arr)<<"\n"<<solve(0, n, K, arr)<<"\n";
	}
	return 0;
}