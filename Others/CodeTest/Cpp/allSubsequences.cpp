#include<bits/stdc++.h>
using namespace std;

void allSubsequence(vector<vector<int>> &ans, vector<int> &a, vector<int> &arr, int i, int n) {
	if(i>=n) {
		ans.push_back(a);
		return;
	}
	a.push_back(arr[i]);
	allSubsequence(ans, a, arr, i+1, n);
	a.pop_back(arr[i]);
	allSubsequence(ans, a, arr, i+1, n);
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		vector<int>arr(n);
		vector<vector<int>>ans;
		vector<int>a;
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}
		allSubsequence(ans, a, arr, 0, n);
		for(auto array:ans) {
			for(int val:array) {
				cout<<val<<" - ";
			}
			cout<<endl;
		}
	}
	return 0;
}