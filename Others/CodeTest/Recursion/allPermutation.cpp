#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &arr, vector<int> &util, int n) {
	if(temp.size()>=n) {
		ans.push_back(temp);
		return;
	}
	for(int i=0; i<n; ++i) {
		if(!util[i]) {
			util[i] = 1;
			temp.push_back(arr[i]);
			solve(ans, temp, arr, util, n);
			util[i] = 0;
			temp.pop_back(  );
		}
	}
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		vector<int>arr(n);
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}
		vector<int>temp;
		vector<int>util(n, 0);
		vector<vector<int>> ans;
		solve(ans, temp, arr, util, n);
		for(auto it:ans) {
			for(int i:it) {
				cout<<i<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}