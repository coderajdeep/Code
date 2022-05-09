#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() {
		val = 0;
		next = nullptr;
	} 
	ListNode(int x) {
		val = x;
		next = nullptr;
	}
	ListNode(int x, ListNode *next) {
		val = x;
		this->next = next;
		// will verify later if use of "this" is correct or not !!
	}
};

int main() {
	cout<<"LinkedList"<<"\n";
	return 0;
}