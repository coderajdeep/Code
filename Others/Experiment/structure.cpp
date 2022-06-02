#include<iostream>
using namespace std;

struct value {
	int x;
	int *arr;
};

value foo() {
	cout<<"Hello\n";
	// value a;
	// a.x = 10;
	int *a = new int[5];
	return {1, a};
}

int main() {
	value A = foo();
	cout<<A.x<<" "<<A.arr[1]<<" "<<A.arr[0]<<endl;
	return 0;
}