// leetcode 19

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) {
            return head;
        }
        
        ListNode *curr = head, *p = head, *prev = NULL;
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
        
        // it will happen when numberOfNodes < n
        if(flag==false) {
            return head;
        }
        
        // it will happen when numberOfNodes == n
        // so we need to delete the first node
        if(!p->next) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        p = p->next;
        
        while(p) {
            prev = curr;
            curr = curr->next;
            p = p->next;
        }
        
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
};