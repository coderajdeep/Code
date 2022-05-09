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

// leetcode 203

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        // if the 1st node == val
        while(head and (head->val)==val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        
        if(!head) {
            return head;
        }
        
        ListNode *curr = head;
        
        while(curr and curr->next) {
            if((curr->next->val)==val) {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};