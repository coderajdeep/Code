#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int n, int W) {
	if(W==0 || n==0) {
		return 0;
	}
	if(W<wt[n-1]) {
		return knapsack(wt, val, n-1, W);
	}
	return max(knapsack(wt, val, n-1, W), val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]));
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n, W;
		cin>>n>>W;
		int wt[n], val[n];

		for(int i=0; i<n; ++i) {
			cin>>wt[i];
		}
		for(int i=0; i<n; ++i) {
			cin>>val[i];
		}

		cout<<knapsack(wt, val, n, W)<<endl;
	}

	return 0;
}