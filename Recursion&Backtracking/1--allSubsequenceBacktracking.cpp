// Print all the subsequence

#include<iostream>
#include<vector>
using namespace std;

void all(int index, int n, int *arr, vector<vector<int>> &ans, vector<int> &temp) {
	if(index==n) {
		ans.push_back(temp);
		return;
	}
	temp.push_back(arr[index]);
	all(index+1, n, arr, ans, temp);
	temp.pop_back();
	all(index+1, n, arr, ans, temp);
}

void all2(int index, int n, int *arr, vector<vector<int>> &ans2, vector<int> &temp2) {
	if(index==n) {
		ans2.push_back(temp2);
		return;
	}
	//temp2.push_back(arr[index]);
	all2(index+1, n, arr, ans2, temp2);
	//temp2.pop_back();
	temp2.push_back(arr[index]);
	all2(index+1, n, arr, ans2, temp2);
	temp2.pop_back();
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}
		vector<vector<int>>ans;
		vector<int>temp;
		vector<vector<int>>ans2;
		vector<int>temp2;
		all(0, n, arr, ans, temp);
		all2(0, n, arr, ans2, temp2);

		for(auto a:ans) {
			for(int e:a) {
				cout<<e<<" ";
			}
			cout<<"\n";
		}
		cout<<endl;

		for(auto a:ans2) {
			for(int e:a) {
				cout<<e<<" ";
			}
			cout<<"\n";
		}
		cout<<endl;
	}
	return 0;
}