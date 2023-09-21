// Find where the loop begin in linkedlist -- leetcode 142

// Time complexity O(n)
// Space complexity O(n)
// Using unordered_set
ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*>hashNode;
    while(head) {
        if(hashNode.find(head) != hashNode.end()) {
            return head;
        }
        hashNode.insert(head);
        head = head->next;
    }
    return nullptr;
}

// Time complexity O(n)
// Space complexity O(1)
// Slow and fast pointer approach
ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head;
    bool isLoopExist = false;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) {
            isLoopExist = true;
            break;
        }
    }
    if(!isLoopExist) {
        return nullptr;
    }
    slow = head;
    while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}