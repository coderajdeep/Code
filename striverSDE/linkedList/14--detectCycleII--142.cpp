// Find where the loop begin in linkedlist -- leetcode 142

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