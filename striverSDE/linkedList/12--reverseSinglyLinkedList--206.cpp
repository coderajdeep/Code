// Reverse a linkedlist -- leetcode 206

// Iterative way
// Time complexity O(n)
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *prev = nullptr, *curr = head, *nxt = nullptr;
    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// Recursive solution
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}