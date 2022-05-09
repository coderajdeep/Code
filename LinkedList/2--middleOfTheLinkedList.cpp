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

// leetcode - 876

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(!head or !head->next) {
            return head;
        }
        
        ListNode *slow = head, *fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // fast==NULL => LinkedList size is even (sise == 2*count) if we put a counter inside the loop
        // fast->next==NULL => LinkedList size is odd (size == 2*count + 1)
        
        return slow;
    }
};