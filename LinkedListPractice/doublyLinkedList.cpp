#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
	Node(int x) {
		data = x;
		prev = NULL;
		next = NULL;
	}
};

// O(n)
void printListRecursive(Node *head) {
	if(!head) {
		cout<<"\n";
		return;
	}
	cout<<head->data<<" ";
	printListRecursive(head->next);
}

// O(n)
void printList(Node *head) {
	if(!head) {
		cout<<"\n";
		return;
	}

	Node *p = head;

	while(p) {
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<"\n";
}

// O(n)
int sizeOfLinkedListRecursive(Node *head) {
	if(!head)
		return 0;
	return 1 + sizeOfLinkedListRecursive(head->next);
}

// O(n)
int sizeOfLinkedList(Node *head) {
	if(!head)
		return 0;
	Node *p = head;
	int count = 0;

	while(p) {
		++count;
		p = p->next;
	}
	return count;
}

// O(1)
Node *addFirst(Node *head, int key) {
	Node *temp = new Node(key);
	if(!head) {
		head = temp;
	}
	else {
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	return head;
}

// O(n)
Node *addLast(Node *head, int key) {
	Node *temp = new Node(key);
	if(!head) {
		head = temp;
	}
	else {
		Node *p = head;
		while(p && p->next) {
			p = p->next;
		}
		p->next = temp;
		temp->prev = p;
	}
	return head;
}

int main() {

}