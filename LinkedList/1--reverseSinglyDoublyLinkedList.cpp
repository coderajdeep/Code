/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// leetcode 206

class Solution {
public:
    
    // Reverse a singly linked list
    
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) {
            return head;
        }
        
        ListNode *curr = head, *nxt = NULL, *prev = NULL;
        
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

// leetcode 206
// recursive way

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) {
            return head;
        }
        
        ListNode *temp = reverseList(head->next);
        
        // this part is tricky
        // just dry run you will understand
        // start with two nodes (means linkedList size == 2)
        
        head->next->next = head;
        head->next = nullptr;
        
        return temp;
    }
};



// Reverse doubly linkedList - geeks
// iterative

Node* reverseDLL(Node * head) {
    //Your code here
    if(!head or !head->next) {
        return head;
    }
    
    Node *prev = NULL, *curr = head;
    
    while(curr) {
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->prev;
    }
    return prev;
}

// Reverse doubly linked list - hacker Rank
// iterative

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(!llist or !llist->next) {
        return llist;
    }
    
    DoublyLinkedListNode *curr = llist, *prev = NULL;
    
    while(curr) {
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->prev;
    }
    
    return prev;
}

// recursive way
// https://www.geeksforgeeks.org/reverse-doubly-linked-list-using-recursion/


Node* reverseDLL(Node * head) {
    //Your code here
    if(!head) {
        return head;
    }
    
    Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    
    if(!head->prev) {
        return head;
    }
    
    return reverseDLL(head->prev);
}