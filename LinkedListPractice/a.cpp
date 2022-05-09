#include <iostream>
#include <vector>
using namespace std;

// for non-negative elements only

bool subarrayWithGivenSum(vector<int> &arr, int target) {
	int n = arr.size();
	int curr = arr[0];
	int start = 0;

	for(int i=1; i<=n; ++i) {
		while(curr>target && start<i-1) {
			curr = curr - arr[start];
			++start;
		}
		if(curr == target) {
			cout<<start<<" "<<(i-1)<<"\n";
			return true;
		}
		if(i<n){
			curr += arr[i];
		}
	}
	return false;
}

// for positive elements only
// this is not correct
// this will never check for last element

bool subarrayWithGivenSum2(vector<int> &arr, int target) {
	int n = arr.size();
	int curr = arr[0];
	int start = 0;

	for(int i=1; i<n; ++i) {
		while(curr>target && start<i) {
			curr = curr - arr[start];
			++start;
		}
		if(curr == target) {
			cout<<start<<" "<<(i-1)<<"\n";
			return true;
		}
		
		curr += arr[i];
		
	}
	return false;
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n, target;
		cin>>n>>target;
		vector<int>arr(n);
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}

		// for(int i=0; i<n; ++i) {
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<"\n";

		// vector<int>ans = rightRotation(arr, d);

		// for(int i=0; i<ans.size(); ++i) {
		// 	cout<<ans[i]<<" ";
		// }

		cout<<subarrayWithGivenSum2(arr, target)<<"\n";
		return 0;
	}

}