// leetcode 92

// very very important

class Solution {
public:
    
    ListNode* reverseList(ListNode *head) {
        if(!head or !head->next) {
            return head;
        }
        
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head or !head->next or (left>=right)) {
            return head;
        }
        
        bool flag = false;
        int count = 1;
        ListNode *prev = NULL, *curr = head, *end = NULL;
        
        if(left==1) {
            flag = true;
        }
        else {
            while(curr) {
                prev = curr;
                if(count == (left-1)) {
                    break;
                }
                ++count;
                curr = curr->next;
            }
        }
        
        
        while(curr) {
            end = curr;
            if(count == right) {
                break;
            }
            ++count;
            curr = curr->next;
        }
        
        ListNode *nextOfEnd = end->next;
        end->next = NULL;
        ListNode *newHead = NULL;
        
        
        if(flag) {
            newHead = reverseList(head);
            head->next = nextOfEnd;
            head = newHead;
        }
        else {
            ListNode *newEnd = prev->next;
            newHead = reverseList(prev->next);
            newEnd->next = nextOfEnd;
            prev->next = newHead;
        }
        
        return head;
    }
};