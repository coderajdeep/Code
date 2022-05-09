// leetcode 141
// very important question

// Time O(n)
// space O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head or !head->next) {
            return false;
        }
        
        ListNode *slow = head, *fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                return true;
            }
        }
        return false;
    }
};


// Time O(n)
// space O(n)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head or !head->next) {
            return false;
        }
        
        unordered_set<ListNode*>s;
        ListNode *curr = head;
        
        while(curr) {
            if(s.find(curr)!=s.end()) {
                return true;
            }
            s.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};