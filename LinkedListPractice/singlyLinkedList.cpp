#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int val) {
		data = val;
		next = NULL;
	}
};

// O(n)
void printList(Node *head) {

	Node *p = head;

	while(p) {
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<"\n";
}

// O(n)
void printListRecursive(Node *head) {
	if(head) {
		cout<<head->data<<" ";
		printListRecursive(head->next);
	}
	cout<<"\n";
}


// O(n)
void printListInReverseOrderRecursive(Node *head) {
	if(!head)
		return;
	printListInReverseOrderRecursive(head->next);
	cout<<head->data<<" ";
}

// O(n)
int sizeOfLinkedList(Node *head) {
	if(!head)
		return 0;

	Node *p = head;
	int count = 0;

	while(p) {
		count += 1;
		p = p->next;
	}

	return count;
}

// O(n)
int sizeOfLinkedListRecursive(Node *head) {
	if(!head)
		return 0;
	return 1 + sizeOfLinkedListRecursive(head->next);
}

// O(n)
int searchInLinkedList(Node *head, int key) {
	if(!head)
		return -1;

	Node *p = head;
	int index = 0;

	while(p) {
		if((p->data)==key) {
			return index;
		}
		p = p->next;
		++index;
	}

	// if key is not present
	// return -1
	return -1;
}

// O(n)
int searchInLinkedListRecursive(Node *head, int key, int index) {
	if(!head)
		return -1;
	if(head->data==key)
		return index;
	return searchInLinkedListRecursive(head->next, key, index+1);
}


// O(1)
Node *addFirst(Node *head, int val) {

	Node *temp = new Node(val);

	if(head==NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return head;
}

// O(n)
// we can add last in O(1) if we store tail of linked list
Node *addLast(Node *head, int val) {

	Node *temp = new Node(val);

	if(head==NULL) {
		head = temp;
		return head;
	}

	Node *p = head;

	while(p && p->next) {
		p = p->next;
	}

	p->next = temp;
	
	return head;
}

// O(1)
Node *deleteFirst(Node *head) {
	if(!head)
		return head;

	head = head->next;
	return head;
}

// O(n)
Node *deleteLast(Node *head) {
	if(!head || !head->next) {
		// this is optional
		// head = NULL;
		return NULL;
	}

	Node *p = head, *prev = NULL;

	while(p && p->next) {
		prev = p;
		p = p->next;
	}

	prev->next = NULL;
	return head;

}

// O(n)
// Iterative and recursive
Node *reverseLinkedList(Node *head) {
	if(!head)
		return NULL;

	Node *curr = head, *prev = NULL, *nxt = NULL;

	while(curr) {
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	return prev;
}

// O(n)
// 0 based indexing
Node *insertAtPos(Node *head, int val, int pos) {
	Node *temp = new Node(val);

	if(pos==0) {
		if(!head) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
		return head;
	}

	if(!head) {
		// this is optional
		// temp = NULL;
		return NULL;
	}

	int count = 0;
	Node *p = head;

	// Here we are handling the cases where pos>0 and head != NULL
	// if pos == size, this case will be handled here
	while(p) {
		if((count+1)==pos) {
			temp->next = p->next;
			p->next = temp;
			return head;
		}
		p = p->next;
		++count;
	}

	// when pos>=size (pos is zero based index)
	// this is optional
	// temp = NULL;
	return head;

}

// O(n)
Node *insertAfter(Node *head, int val, int element) {
	if(!head)
		return NULL;

	Node *temp = new Node(val);

	Node *p = head;

	if(p) {
		if((p->data)==element) {
			temp->next = p->next;
			p->next = temp;
			return head;
		}
		p = p->next;
	}
	// if element is not found
	// this is optional
	// temp = NULL;
	return head;

}

// O(n)
Node *insertBefore(Node *head, int val, int element) {
	if(!head)
		return NULL;

	Node *temp = new Node(val);

	if((head->data)==element) {
		temp->next = head;
		head = temp;
		return head;
	}

	Node *p = head;

	while(p && p->next) {
		if(p->next->data == element) {
			temp->next = p->next;
			p->next = temp;
			return head;
		}
		p = p->next;
	}

	// if element is not found
	// temp = NULL;
	// this is optional
	return head;
}

// O(n)
Node *deleteElement(Node *head, int element) {
	if(!head)
		return NULL;
	if((head->data)==element) {
		head = head->next;
		return head;
	}

	Node *p = head;

	while(p && p->next) {
		if((p->next->data)==element) {
			p->next = p->next->next;
			return head;
		}
		p = p->next;
	}

	// if element is not found
	return head;
}

// O(n)
Node *deleteAtPos(Node *head, int pos) {
	if(!head)
		return NULL;

	if(pos==0) {
		head = head->next;
		return head;
	}

	Node *p = head;
	int count = 0;

	while(p) {
		if((count+1)==pos) {
			// if we don't check this condition the pos==size will give segmentation error
			if(p->next) {
				p->next = p->next->next;
				return head;
			}

		}
		++count;
		p = p->next;
	}

	return head;
}

int main() {
	return 0;
}
