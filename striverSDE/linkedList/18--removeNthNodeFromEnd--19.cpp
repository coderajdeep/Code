// Remove N-th node from end of the linkedlist -- leetcode 19

// Time complexity O(n)
// Space complexity O(1)
// Single traversal
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // this is for when n==1 and head==nullptr
    if(!head) {
        return head;
    }
    ListNode *ptr = head, *curr = head;
    for(int i=1; i<n; ++i) {
        // when n is greater than the length of linkedlist
        if(!ptr) {
            return nullptr;
        }
        ptr = ptr->next;
    }
    ListNode *temp = nullptr;
    // When n == size of linkedlist
    // So need to delete the first node
    if(!ptr->next) {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *prev = nullptr;
    while(ptr && ptr->next) {
        prev = curr;
        curr = curr->next;
        ptr = ptr->next;
    }
    // we need to delete curr node
    // prev is the previous of curr node
    prev->next = curr->next;
    delete curr;
    return head;
}


// Time complexity O(n)
// Space complexity O(1)
// Single traversal
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // this is for when n==1 and head==nullptr
    if(!head) {
        return head;
    }
    ListNode *ptr = head, *curr = head;
    for(int i=1; i<n; ++i) {
        // when n is greater than the length of linkedlist
        if(!ptr) {
            return nullptr;
        }
        ptr = ptr->next;
    }
    ListNode *prev = head;
    while(ptr && ptr->next) {
        prev = curr;
        curr = curr->next;
        ptr = ptr->next;
    }
    ListNode *temp = nullptr;
    // when n == length of linkedlist
    if(prev == curr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    else {
        temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    return head;
}