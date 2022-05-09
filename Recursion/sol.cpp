#include<bits/stdc++.h>
using namespace std;

// find factorial
long long fact(int n) {
	if(n<=1) return 1;
	return n * fact(n-1);
}

// print name n times
void printName(int n) {
	if(n==0) return;
	cout<<"rajdeep\n";
	printName(--n);
}

// print linearly from 1 to n
void printNumbers(int cnt, int n) {
	if(cnt>n) return;
	cout<<cnt<<" ";
	printNumbers(++cnt, n);
}

// print linearly from n to 1
void printNumbers(int n) {
	if(n==0) return;
	cout<<n<<" ";
	printNumbers(--n);
}

// print linearly from 1 to n
void printNumbersBackTracking(int n) {
	if(n==0) return;
	printNumbersBackTracking(n-1);
	cout<<n<<" ";
}

// print linearly from n to 1
void printNumbersBackTracking(int cnt, int n) {
	if(cnt) return;
	printNumbersBackTracking(n-1);
	cout<<n<<" ";
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		// cout<<fact(n)<<"\n";
		printNumbers(n);
		cout<<endl;
		printNumbers(1, n);
		cout<<endl;
		printNumbersBackTracking(n);
	}
	return 0;
}