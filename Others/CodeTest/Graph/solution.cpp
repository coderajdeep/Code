#include<bits/stdc++.h>
using namespace std;

void getMinPrice(int n, int k, vector<vector<int>> &table, vector<int> &hash, int row, int &ans) {
	if(row>=k) {
		return;
	}

	for(int i=0; i<n; ++i) {
		if(table[row][i] != -1) {
			if(hash[i]==-1) {
				ans = min(ans, table[row][i]);
			}
		}
	}
}

int solve(int n, int k, vector<int> &req, vector<int> &prices, vector<vector<int>> &minerals) {

	vector<vector<int>> table(k, vector<int>(n, -1));

	for(int i=0; i<k; ++i) {
		for(int j=0; j<n; ++j) {
			if(binary_search(minerals[j].begin(), minerals[j].end(), req[i])) {
				table[i][j] = prices[j];
			}
		}
	}

	int row = 0;
	vector<int> hash(n, -1);
	getMinPrice(n, k, table, hash, row, ans);
	return ans;
}

int main() {
	int T;
	cin>>t;
	for(int t=0; i<T; ++t) {

		// taking inputs
		int k;
		cin>>k;
		int req[k];

		for(int i=0; i<k; ++i) {
			cin>>req[i];
		}

		int n,s;
		cin>>n;
		int prices[n];
		vector<vector<int>>minerals(n);
		
		for(int i=0; i<n; ++i) {
			cin>>prices[i];
			cin>>s;
			vector<int>temp(s);
			for(int j=0; j<s; ++j) {
				cin>>temp[j];
			}
			minerals[i] = temp;
		}
		// inputj taking is completed

		int ans = solve();
		cout<<t<<" # "<<ans<<endl;
	}
	return 0;
}