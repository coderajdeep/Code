// leetcode 148

class Solution {
public:
    
    ListNode* getMiddle(ListNode *head) {
        if(!head or !head->next) {
            return head;
        }
        
        ListNode *slow = head, *fast = head, *prev = head;
        
        while(fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        return slow;
    }
    
    ListNode* mergeList(ListNode *l1, ListNode *l2) {
        
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        
        ListNode *head = NULL, *p = NULL;
        
        if(l1->val < l2->val) {
            head = l1; 
            l1 = l1->next;
        }
        else {
            head = l2; 
            l2 = l2->next;
        }
        
        p = head;
        
        while(l1 and l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if(l1) {
            p->next = l1;
        }
        else if(l2) {
            p->next = l2;
        }
        
        return head;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) {
            return head;
        }
        
        ListNode* middle = getMiddle(head);
        
        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(middle);
        ListNode* newHead = mergeList(head1, head2);
        
        return newHead;
    }
};