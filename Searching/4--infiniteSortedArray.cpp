#include<iostream>
using namespace std;

int binarySearch(int arr[], int lo, int hi, int key) {
	while(lo<=hi) {
		int mid = lo + (hi-lo)/2;
		if(arr[mid]==key) {
			return mid;
		}
		else if(key<arr[mid]) {
			hi = mid-1;
		}
		else {
			lo = mid+1;
		}
	}
	return -1;
}

int searchInInfiniteSortedArray(int arr[], int key) {
	if(arr[0]==key) {
		return 0;
	}

	int i = 1;

	while(key>arr[i]) {
		i *= 2;
	}

	if(key==arr[i]) {
		return i;
	}

	return binarySearch(arr, (i/2)+1, i-1, key);
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n, key;
		cin>>n>>key;
		int arr[n];
		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}
		cout<<searchInInfiniteSortedArray(arr, key)<<"\n";
	}
	return 0;
}

/*

input
2
25 24
1 2 4 9 11 18 20 24 30 33 41 45 46 47 48 49 50 51 52 53 54 55 56 57 58
25 35
1 2 4 9 11 18 20 24 30 33 41 45 46 47 48 49 50 51 52 53 54 55 56 57 58

output 
7
-1
*/