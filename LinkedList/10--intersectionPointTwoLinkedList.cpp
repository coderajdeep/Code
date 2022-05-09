// leetcode 160

// space O(n)
// will reduce space

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB) {
            return NULL;
        }
        
        unordered_set<ListNode*>s;
        ListNode *curr = headA;
        
        while(curr) {
            s.insert(curr);
            curr = curr->next;
        }
        
        curr = headB;
        
        while(curr) {
            if(s.find(curr)!=s.end()) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
};


// Time O(n+m)
// Space O(1)

class Solution {
public:
    
    int getLength(ListNode *head) {
        if(!head) {
            return 0;
        }
        if(!head->next) {
            return 1;
        }
        
        ListNode *slow = head, *fast = head;
        int count = 0;
        
        while(fast and fast->next) {
            ++count;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) {
            return (2*count + 1);
        }
        return 2*count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB) {
            return nullptr;
        }
        
        int n1 = getLength(headA);
        int n2 = getLength(headB);
        
        int d;
        bool first = true;
        
        if(n1<n2) {
            d = n2-n1;
            first = false;
        }
        else {
            d = n1-n2;
        }
        
        int count = 0;
        
        if(first) {
            while(headA) {
                if(count==d) {
                    break;
                }
                ++count;
                headA = headA->next;
            }
        }
        else {
            while(headB) {
                if(count==d) {
                    break;
                }
                ++count;
                headB = headB->next;
            }
        }
        
        while(headA and headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};