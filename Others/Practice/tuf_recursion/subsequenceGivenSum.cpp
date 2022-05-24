#include <iostream>
#include <vector>
using namespace std;

// void subsequenceWithGivenSum(int index, int n, int &sum, int k, int *arr, vector<int> &ans, vector<int> &temp, bool &flag) {
// 	if(index==n) {
// 		if(sum==k && flag)  {
// 			ans = temp;
// 			flag = false;
// 		}
// 		return;
// 	}
// 	temp.push_back(arr[index]);
// 	sum+= arr[index];
// 	subsequenceWithGivenSum(index+1, n, sum, k, arr, ans, temp, flag);
// 	temp.pop_back();
// 	sum -= arr[index];
// 	subsequenceWithGivenSum(index+1, n, sum, k, arr, ans, temp, flag);
// }

bool subsequenceWithGivenSum(int index, int n, int &sum, int k, int *arr, vector<int> &ans, vector<int> &temp, bool &flag) {
	if(index==n) {
		if(sum==k and flag) {
			ans = temp;
			return true;
		}
		return false;
	}
	temp.push_back(arr[index]);
	sum += arr[index];
	if(subsequenceWithGivenSum(index+1, n, sum, k, arr, ans, temp, flag)) return true;
	temp.pop_back();
	sum -= arr[index];
	if(subsequenceWithGivenSum(index+1, n, sum, k, arr, ans, temp, flag)) return true;
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		int arr[n];
		for(int i=0; i<n; ++i) cin>>arr[i];
		vector<int> ans, temp;
		bool flag = true;
		int sum = 0;
		subsequenceWithGivenSum(0, n, sum, k, arr, ans, temp, flag);
		for(int i=0; i<ans.size(); ++i) {
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}