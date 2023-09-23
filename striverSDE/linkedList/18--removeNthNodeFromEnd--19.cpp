// Remove N-th node from end of the linkedlist -- leetcode 19

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