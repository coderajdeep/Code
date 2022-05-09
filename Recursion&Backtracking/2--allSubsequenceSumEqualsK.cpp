#include<iostream>
#include<vector>

using namespace std;

void subsequence(int index, int n, int k, vector<vector<int>> &ans, vector<int> &temp, int *arr) {
	if(index==n) {
		int sum = 0;
		for(int x:temp) {
			sum += x;
		}
		if(sum==k) ans.push_back(temp);
		return;
	}

	temp.push_back(arr[index]);
	subsequence(index+1, n, k, ans, temp, arr);
	temp.pop_back();
	subsequence(index+1, n, k, ans, temp, arr);
}

void subsequence2(int index, int n, int k, int sum, vector<vector<int>> &ans2, vector<int> &temp2, int *arr) {
	if(index==n) {
		if(sum==k) ans2.push_back(temp2);
		return;
	}

	temp2.push_back(arr[index]);
	sum += arr[index];
	subsequence2(index+1, n, k, sum, ans2, temp2, arr);
	temp2.pop_back();
	sum -= arr[index];
	subsequence2(index+1, n, k, sum, ans2, temp2, arr);
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n, k;
		cin>>n>>k;
		int arr[n];
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}

		vector<vector<int>> ans;
		vector<int> temp;

		vector<vector<int>> ans2;
		vector<int> temp2;

		subsequence(0, n, k, ans, temp, arr);
		subsequence2(0, n, k, 0, ans2, temp2, arr);
		for(auto it:ans) {
			for(int x:it) {
				cout<<x<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";

		for(auto it:ans2) {
			for(int x:it) {
				cout<<x<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}

/*

input

1
7 6
4 18 6 11 2 4 0

output

4 2 0 
4 2 
6 0 
6 
2 4 0 
2 4 

*/