#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string &s, int lo, int hi) {
	if(lo>=hi) return true;
	if(s[lo]!=s[hi]) return false;
	isPalindrom(s, lo+1, hi-1);
}

void printFibonaci(int a, int b, int n) {
	cout<<(a+b)<<" ";
	printFibonaci(b, a+b, n-1);
}

int nthFibonaci(int n) {
	if(n<=1) return n;
	return nthFibonaci(n-1) + nthFibonaci(n-2);
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		// string s;  
		// cin>>s;
		// cout<<isPalindrom(s, 0, s.size()-1)<<"\n";
		int n;
		cin>>n;
		cout<<nthFibonaci(n)<<endl;
		// printFibonaci(0, 1, 5);
	}
	return 0;
}