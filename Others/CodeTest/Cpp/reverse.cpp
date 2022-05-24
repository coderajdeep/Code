#include<bits/stdc++.h>
using namespace std;

// this will not work
// need to figure it out
// void reverseArray(int *arr, int n) {
// 	if(n==1) return;
// 	swap(arr[0], arr[n-1]);
// 	reverseArray(arr+1, n-1);
// }

void reverseArray2(int *arr, int lo, int hi) {
	if(lo>=hi) return;
	swap(arr[lo], arr[hi]);
	reverseArray2(arr, lo+1, hi-1);
}

void printArray(int *arr, int n) {
	for(int i=0; i<n; ++i) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr1[n], arr2[n];

		for(int i=0; i<n; ++i) {
			int x;
			cin>>x;
			arr1[i]=arr2[i]=x;
		}

		printArray(arr1, n);
		printArray(arr2, n);


		// reverseArray(arr1, n);
		reverseArray2(arr2, 0, n-1);

		printArray(arr1, n);
		printArray(arr2, n);
	}
}