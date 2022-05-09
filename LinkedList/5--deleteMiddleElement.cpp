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

// leetcode 2095

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or !head->next) {
            head = NULL;
            return head;
        }
        
        ListNode *slow = head, *fast = head, *prev = head;
        
        while(fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        delete slow;
        
        return head;
    }
};