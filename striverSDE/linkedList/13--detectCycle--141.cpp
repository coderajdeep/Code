// Detect cycle in linkedlist -- leetcode 141

// Using unordered_set
// Time complexity O(n)
// Space complexity O(n)
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> nodeHash;
    while(head) {
        if(nodeHash.find(head)!=nodeHash.end()) {
            return true;
        }
        nodeHash.insert(head);
        head = head->next;
    }
    return false;
}


// Time complexity O(n)
// Space complexity O(1)
// Using tortoise hare or slow fast pointer algorithm
bool hasCycle(ListNode *head) {
    if(!head || !head->next) {
        return false;
    }
    ListNode *slow = head, *fast = head;
    // Even when number of nodes is one or two
    // This will be handled with below logic
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            return true;
        }
    }
    return false;
}