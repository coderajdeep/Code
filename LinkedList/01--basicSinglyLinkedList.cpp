// 1
// Singly linkedList Traversal
// https://practice.geeksforgeeks.org/problems/print-linked-list-elements/1

// Iterative method
class Solution {
    public:
    void display(Node *head) {
        while(head) {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
};

// Recursive method
class Solution {
    public:
    void display(Node *head) {
        if(!head) {
            return;
        }
        cout<<head->data<<" ";
        display(head->next);
    }
};

// 2
// Insert at Beginning and End
// https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1/

class Solution {
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node *temp = new Node(x);
       temp->next = head;
       return temp; // temp is current head;
    }
    
    //Recursive method
    Node *insertAtEnd(Node *head, int x) {
       // Your code here
       if(!head) {
           return new Node(x);
       }
       if(!head->next) {
           head->next = new Node(x);
           return head;
       }
       
       head->next = insertAtEnd(head->next, x);
       return head;
    }

    // Iterative method
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       Node *temp = new Node(x);
       if(!head) {
           return temp;
       }
       Node *curr = head;
       while(curr->next) {
           curr = curr->next;
       }
       curr->next = temp;
       return head;
    }
};

// 3
// Delete head/1st Node
Node* removeFirstNode(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeFirstNode(Node *head){
    if(head==NULL) return NULL;
    
    Node *temp=head->next;
    delete(head);
    return temp;
}

// 4
// Delete last node
// Iterative method
// https://ide.geeksforgeeks.org/FqO0YKG3wx
Node* removeLastNode(Node* head) {
	if (!head) return NULL;
	if (!head->next) {
		delete head;
		return NULL;
	}
	Node* curr = head;
	while (curr->next->next)
		curr = curr->next;

	// Delete last node
	delete (curr->next);

	// Change next of second last
	curr->next = NULL;
	return head;
}

// Recursive method
// https://ide.geeksforgeeks.org/o8sY0ywYSQ
Node* removeLastNode(Node* head) {
	if (!head)
		return nullptr;

	if (!head->next) {
		delete head;
		return nullptr;
	}

	if(!head->next->next) {
    	delete head->next;
      	head->next = nullptr;
      	return head;
    }
  
  	head->next = removeLastNode(head->next);
  	return head;
}


// 5
// Insert at Kth position
// https://workat.tech/codes/wuh784o8
ListNode* addAtkthElement (ListNode* head, int k, ListNode* newElement) {
	// head==nullptr and head!=nullptr ; both condition will be handled
	if(k==1) {
		newElement->next = head;
		return newElement; // newElement is new head
	}
	if(!head or k<0) {
		return head;
	}
	int count = 2;
	ListNode *curr = head;
	while(curr) {
		if(count==k) {
			newElement->next = curr->next;
			curr->next = newElement;
			return head;
		}
		++count;
		curr = curr->next;
	}
	// if (sizeOfLinkedList+1)<k 
	// then we can't insert newElement
	return head;
}


// 6
// Count node of linked list
// https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/1/
// Iterative solution
int getCount(struct Node* head){
    if(!head) return 0;
    int count = 0;
    Node *slow = head, *fast = head;
    while(fast and fast->next) {
        ++count;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) {
        return (2*count + 1);
    }
    return (2*count);
}

// recursive solution
int getCount(Node* head){
    if(!head) return 0;
    return (1 + getCount(head->next));
}
int getCount(Node* head){
    if(!head) return 0;
    if(!head->next) return 1;
    return 2 + getCount(head->next->next);
}


// 7
// search in linkedlist
// https://ide.geeksforgeeks.org/xGegfaffFk
// recursive
bool search(Node* head, int x) {
	if (head == NULL) return false;
	if (head->key == x) return true;
	return search(head->next, x);
}
// iterative
bool search(Node* head, int x) {
	if (head == NULL) return false;
	while(head) {
    	if(head->key==x) return true;
      	head = head->next;
    }
  	return false;
}