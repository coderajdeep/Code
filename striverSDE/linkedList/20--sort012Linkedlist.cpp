// Sort array having element 0, 1, 2 -- coding ninjas

// Time complexity O(n)
// Space complexity O(1)
// 2 times traversal
Node* sortList(Node *head){
    if(!head || !head->next) {
        return head;
    }
    int one = 0, two = 0, zero = 0, val;
    Node *ptr = head;
    while(ptr) {
        val = ptr->data;
        if(val == 0) ++zero;
        else if(val == 1) ++one;
        else ++two;
        ptr = ptr->next;
    }
    ptr = head;
    while(ptr) {
        if(zero!=0) {
            ptr->data = 0;
            --zero;
        }
        else if(one!=0) {
            ptr->data = 1;
            --one;
        }
        else {
            ptr->data = 2;
        }
        ptr = ptr->next;
    }
    return head;
}