#include<bits/stdc++.h>
using namespace std;

void swapElement(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}


/*
	BUBBLE SORT

	In 1st traversal [n-1, n-1] part sorted
	In 2nd traversal [n-2, n-1] part sorted
	In 3rd traversal [n-3, n-1] part sorted
	and so on...
*/

vector<int> bubbleSort(vector<int> arr) {

	int n = arr.size();

	// i<n also works
	// but it is not needed
	for(int i=0; i<n-1; ++i) {

		bool flag = true;

		for(int j=0; j<(n-i-1); ++j) {
			if(arr[j]>arr[j+1]) {
				swapElement(arr[j], arr[j+1]);
				flag = false;
			}
		}
		// flag remains true if there is no swap inside inner loop
		// means array is already sorted
		if(flag) {
			break;
		}
	}
	return arr;
}

void bubbleSortUtil(vector<int> &arr, int n) {
	if(n<=1) {
		return;
	}
	if(arr[n-2]>arr[n-1]) {
		swapElement(arr[n-2], arr[n-1]);
	}
	bubbleSortUtil(arr, n-1);
}

vector<int> bubbleSortRecursive(vector<int> arr) {
	int n = arr.size();
	if(n==1) {
		return arr;
	}
	bubbleSortUtil(arr, n);
	return arr;
}


vector<int> selectionSort(vector<int> arr) {

	int n = arr.size();
	int index;

	for(int i=0; i<n-1; ++i) {
		index = i;
		for(int j=i+1; j<n; ++j) {
			if(arr[index]>arr[j]) {
				index = j;
			}
		}
		swapElement(arr[i], arr[index]);
	}
	return arr;
}

/*

	we can use binary search still worst time complexity will be O(n2)

*/


vector<int> insertionSort(vector<int> arr) {

	int n = arr.size();
	int index;

	for(int i=0; i<n-1; ++i) {

		index = i+1;

		while((index>=1) && arr[index-1]>arr[index]) {
			swapElement(arr[index-1], arr[index]);
			--index;
		}
	}
	return arr;
}

vector<int> insertionSort2(vector<int> arr) {

	int n = arr.size();
	int key, index;

	for(int i=0; i<n-1; ++i) {
		key = arr[i+1];
		index = i;
		while(index>=0 && (arr[index]>key)) {
			arr[index+1] = arr[index];
			--index;
		}
		arr[index+1] = key;
	}
	return arr;
}

void merge(vector<int> &arr, int lo, int hi) {

	int mid = lo + (hi-lo)/2;

	vector<int>arr1(arr.begin()+lo, arr.begin()+mid+1);
	vector<int>arr2(arr.begin()+mid+1, arr.begin()+hi+1);

	int i = 0, j = 0, k = lo, n1 = mid-lo+1, n2 = hi-mid;

	while(i<n1 && j<n2 && k<=hi) {

		if(arr1[i]<arr2[j]) {
			arr[k++] = arr1[i++];
		}

		else {
			arr[k++] = arr2[j++];
		}

	}

	while(i<n1 && k<=hi) {

		arr[k++] = arr1[i++];

	}

	while(j<n2 && k<=hi) {

		arr[k++] = arr2[j++];
		
	}
}

void mergeSort(vector<int> &arr, int lo, int hi) {
	if(lo>=hi)
		return;
	int mid = lo + (hi-lo)/2;
	mergeSort(arr, lo, mid);
	mergeSort(arr, mid+1, hi);
	merge(arr, lo, hi);
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

		vector<int>ans1 = bubbleSort(arr);
		for(int i=0; i<n; ++i) {
			cout<<ans1[i]<<" ";
		}
		cout<<"\n";

		vector<int>ans2 = selectionSort(arr);
		for(int i=0; i<n; ++i) {
			cout<<ans2[i]<<" ";
		}
		cout<<"\n";

		vector<int>ans3 = insertionSort(arr);
		for(int i=0; i<n; ++i) {
			cout<<ans3[i]<<" ";
		}
		cout<<"\n";

		vector<int>ans4 = insertionSort2(arr);
		for(int i=0; i<n; ++i) {
			cout<<ans4[i]<<" ";
		}
		cout<<"\n";

		vector<int>ans5(arr.begin(), arr.end());
		mergeSort(ans5, 0, ans5.size()-1);
		for(int i=0; i<n; ++i) {
			cout<<ans5[i]<<" ";
		}
		cout<<"\n\n";
	}
}
