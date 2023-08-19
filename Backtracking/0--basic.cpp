// 1
// reverse an array
// https://www.codingninjas.com/studio/problems/reverse-the-array_1262298?leftPanelTab=0
#include <bits/stdc++.h> 
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void solve(int start, int end, vector<int>& arr) {
	if(start>=end) return;
	swap(arr[start], arr[end]);
	solve(start+1, end-1, arr);
}
void reverseArray(vector<int> &arr , int m)
{
	int n = arr.size();
	solve(m+1, n-1, arr);
}


// 2
// check if a string is palindrom or not
// https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633?leftPanelTab=0
#include <bits/stdc++.h>
char lowerCase(char ch) {
    if(ch>='A' && ch<='Z') return (ch+32);
    return ch;
}
bool solve(int start, int end, string& str) {
    if(start>=end) return true;
    if(str[start]!=str[end]) return false;
    return solve(start+1, end-1, str);
}
string filterString(string& str) {
    string s = "";
    for(char ch:str) {
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')) {
            s.push_back(lowerCase(ch));
        }
    }
    return s;
}
bool checkPalindrome(string s)
{
    string str = filterString(s);
    return solve(0, str.size()-1, str);
}

// 3
// print  all subsequence 
// https://www.codingninjas.com/studio/problems/print-subsequences_624391?leftPanelTab=0
void solve(int index, char *arr, string& str) {
    if(arr[index]=='\0') {
        cout<<(str.empty()?"":str)<<endl;
        return;
    }
    solve(index+1, arr, str);
    str.push_back(arr[index]);
    solve(index+1, arr, str);
    str.pop_back();
}
void printSubsequences(char input[]) {
    string str;
    solve(0, input, str);
}

// 4
// print all subsequence with a given sum
#include <iostream>
#include <vector>
using namespace std;
void solve(int index, int n, int sum, int *arr, vector<int>& ds) {
	if(index==n) {
		if(sum==0) {
			for(int element:ds) {
				cout<<element<<" ";
			}
			cout<<endl;
		}
		return;
	}
	// including arr[index]
	ds.push_back(arr[index]);
	solve(index+1, n, sum - arr[index], arr, ds);
	// excluding arr[index]
	ds.pop_back();
	solve(index+1, n, sum, arr, ds);
}
int main() {
	int arr[5] = {1, 3, 4, 0, 2};
	vector<int> ds;
	solve(0, 5, 4, arr, ds);
	return 0;
}

// 5
// print one subsequence with a given sum
#include <iostream>
#include <vector>
using namespace std;
bool solve(int index, int n, int sum, int *arr, vector<int>& ds) {
	if(sum==0) {
		for(int element:ds) {
			cout<<element<<" ";
		}
		cout<<endl;
		return true;
	}
	if(index==n) {
		return false;
	}
	// including arr[index]
	ds.push_back(arr[index]);
	if(solve(index+1, n, sum - arr[index], arr, ds)) return true;
	// excluding arr[index]
	ds.pop_back();
	return solve(index+1, n, sum, arr, ds);
}
int main() {
	int arr[5] = {1, 3, 4, 0, 2};
	vector<int> ds;
	cout<<(solve(0, 5, 6, arr, ds)?"True":"False")<<endl;
	return 0;
}