#include<bits/stdc++.h>
using namespace std;

int parent(int i) {
	return (i-1)/2;
}

int left(int i) {
	return (2*i + 1);
}

int right(int i) {
	return (2*i + 2);
}

int getMax(vector<int> &arr, int n) {
	if(n>=1) {
		return arr[0];
	}
	return INT_MIN;
}

void insert(vector<int> &arr, int &n, int key) {
	arr.insert(key);
	n = arr.size();

	while(i!=0 and arr[i]>arr[parent(i)]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

void maxHeapify(vector<int> &arr, int i, int n) {
	int highest = i;
	if(highest<n and arr[highest]<arr[left(i)]) {
		highest = left(i);
	}
	if(highest<)
}

void deleteMax(vector<int> &arr, int &n) {

}

int main() {

}