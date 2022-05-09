/*

Given a non-empty linked list and a positive integer k, return the value of k'th node from the end of the list.

Input: List = 1 —> 2 —> 3 —> 4 —> 5 —> nullptr, k = 3
Output: 3

Assume that k is less than or equal to number of nodes in the linked list.

*/

// https://techiedelight.com/practice/?id=EG76


// geeks
// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/#

int getNthFromLast(Node *head, int n)
{
       // Your code here
       if(!head) {
           return -1;
       }
       
       Node *curr = head, *p = head;
       int count = 1;
       bool flag = false;
       
       while(p) {
           if(count==n) {
               flag = true;
               break;
           }
           ++count;
           p = p->next;
       }
       
       // totalNodes < n
       if(flag==false) {
           return -1;
       }
       
       p = p->next;
       
       while(p) {
           curr = curr->next;
           p = p->next;
       }
       
       return (curr->data);
}


// https://www.techiedelight.com/

class Solution
{
public:

	/*
		A singly-linked list node is defined as:

		class Node
		{
		public:
			int data;				// data field
			Node* next = nullptr; 	// pointer to the next node

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *next): data(data), next(next) {}
		};
	*/

	// this will handle every coner case
	// k>n return -1
	// k==n return head->val 
	// head==nullptr return -1
	int findKthNode(Node* head, int k)
	{
		// Write your code here...
		if(!head) {
			return -1;
		}
		
		Node *curr = head, *p = head;
		int count = 1;
		bool flag = false;
		
		while(p) {
			if(count==k) {
				flag = true;
				break;
			}
			++count;
			p = p->next;
		}
		
		if(flag==false) {
			return -1;
		}
		
		p = p->next;
		
		while(p) {
			curr = curr->next;
			p = p->next;
		}
		
		return (curr->data);
	}
};
