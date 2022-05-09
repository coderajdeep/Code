#include<bits/stdc++.h>
using namespace std;

struct point {
	int x,y;
};

struct student {
	int marks[3];
	int roll;
};

struct keyValue {
	int key;
	char value;
};

bool comp1(point a, point b) {
	return a.x<b.x;
}

bool comp2(point a, point b) {
	return a.y<b.y;
}

bool comp3(keyValue a, keyValue b) {
	return a.key>b.key;
}

bool studentComp(student a, student b) {
	return a.roll>b.roll;
}


// STL sort is stable in nature

int main() {

	int arr[] = {8, 9, 23, 53, 29, 7};

	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<n; ++i) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n";

	sort(arr, arr+n, greater<int>());

	for(int i=0; i<n; ++i) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n";

	point arr1[] = {{-1, 10}, {-1, 2}, {1, 2}, {3, 4}, {0, 7}, {-1, 5}, {2, 2}, {0, 2}};
	point arr2[] = {{-1, 10}, {-1, 2}, {1, 2}, {3, 4}, {0, 7}, {-1, 5}, {2, 2}, {0, 2}};

	n = sizeof(arr1)/sizeof(arr1[0]);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<arr1[i].x<<" "<<arr1[i].y<<" ]  ";
	}
	cout<<"\n\n";

	sort(arr1, arr1+n, comp1);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<arr1[i].x<<" "<<arr1[i].y<<" ]  ";
	}
	cout<<"\n\n";

	sort(arr2, arr2+n, comp2);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<arr2[i].x<<" "<<arr2[i].y<<" ]  ";
	}
	cout<<"\n\n";

	keyValue arr3[] = {{97, 'a'}, {98, 'b'}, {99, 'c'}, {100, 'd'}, {101, 'e'}, {102, 'f'}};
	n = sizeof(arr3)/sizeof(arr3[0]);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<arr3[i].key<<" "<<arr3[i].value<<" ]  ";
	}
	cout<<"\n\n";

	sort(arr3, arr3+n, comp3);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<arr3[i].key<<" "<<arr3[i].value<<" ]  ";
	}
	cout<<"\n\n";

	reverse(arr3, arr3+n);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<arr3[i].key<<" "<<arr3[i].value<<" ]  ";
	}
	cout<<"\n\n";

	student students[] = {{{97, 91, 89}, 1}, {{97, 91, 89}, 2}, {{97, 91, 89}, 3}};

	n = sizeof(students)/sizeof(students[0]);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<students[i].roll<<" - ";
		for(int j=0; j<3; ++j) {
			cout<<students[i].marks[j]<<" ";
		}
		cout<<"]";
	}
	cout<<"\n\n";

	sort(students, students+n, studentComp);

	for(int i=0; i<n; ++i) {
		cout<<"[ "<<students[i].roll<<" - ";
		for(int j=0; j<3; ++j) {
			cout<<students[i].marks[j]<<" ";
		}
		cout<<"]";
	}
	cout<<"\n\n";

	return 0;
}

/*

8 9 23 53 29 7 

53 29 23 9 8 7 

[ -1 10 ]  [ -1 2 ]  [ 1 2 ]  [ 3 4 ]  [ 0 7 ]  [ -1 5 ]  [ 2 2 ]  [ 0 2 ]  

[ -1 10 ]  [ -1 2 ]  [ -1 5 ]  [ 0 7 ]  [ 0 2 ]  [ 1 2 ]  [ 2 2 ]  [ 3 4 ]  

[ -1 2 ]  [ 1 2 ]  [ 2 2 ]  [ 0 2 ]  [ 3 4 ]  [ -1 5 ]  [ 0 7 ]  [ -1 10 ]  

[ 97 a ]  [ 98 b ]  [ 99 c ]  [ 100 d ]  [ 101 e ]  [ 102 f ]  

[ 102 f ]  [ 101 e ]  [ 100 d ]  [ 99 c ]  [ 98 b ]  [ 97 a ]  

[ 97 a ]  [ 98 b ]  [ 99 c ]  [ 100 d ]  [ 101 e ]  [ 102 f ]  

[ 1 - 97 91 89 ][ 2 - 97 91 89 ][ 3 - 97 91 89 ]

[ 3 - 97 91 89 ][ 2 - 97 91 89 ][ 1 - 97 91 89 ]


*/