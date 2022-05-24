#include<iostream>
using namespace std;

long long nthFibonacci(int n) {
	if(n<=1) return n;
	return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<nthFibonacci(n)<<" ";
	}
	return 0;
}

/*

int main() {
	int t;
	cin>>t;
	while(t--) {
		
	}
}

*/