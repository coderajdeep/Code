// leetcode 142
// vecry very important

// Time O(n)
// Space O(n)
// need to solve in constant space

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) {
            return NULL;
        }
        unordered_set<ListNode*>s;
        ListNode *curr = head;
        
        while(curr) {
            if(s.find(curr)!=s.end()) {
                return curr;
            }
            s.insert(curr);
            curr = curr->next;
        }
        
        return NULL;
    }
};


// O(1) space

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        bool hasLoop = false;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                hasLoop = true;
                break;
            }
        }
        if(!hasLoop) {
            return nullptr;
        }
        
        int n = 1;
        
        while(fast->next!=slow) {
            ++n;
            fast = fast->next;
        }
        
        ListNode *curr = head;
        int count = 0;
        
        while(true) {
            if(count==n) {
                break;
            }
            ++count;
            curr = curr->next;
        }
        
        while(true) {
            if(curr==head) {
                return head;
            }
            curr = curr->next;
            head = head->next;
        }
        return nullptr;
    }
};