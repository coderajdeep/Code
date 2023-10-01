// Delete all the nodes equal to K -- coding ninja

// Separately handling when when equals to k
// Time complexity O(n)
// Space complexity O(1)
Node* deleteAllOccurrences(Node* head, int k) {
    // head value is equal to k
    while(head && head->data == k) {
        head = head->next;
    }
    if(!head) {
        return head;
    }
    Node *root = head;
    while(head) {
        if(head->data == k) {
            // head can't be equal to k
            // that's why head->prev always not null
            head->prev->next = head->next;
            // if head is not the last last element
            if(head->next) {
                head->next->prev = head->prev;
            }
        }
        head = head->next;
    }
    return root;
}

// Time complexity O(n)
// Space complexity O(1)
Node* deleteAllOccurrences(Node* head, int k) {
    Node* root = head;
    while(head) {
        if(head->data == k) {
            // if head is not the first element
            if(head->prev) {
                head->prev->next = head->next;
                // if head is not the last last element
                if(head->next) {
                    head->next->prev = head->prev;
                }
                head = head->next;
            }
            // head is the first elemnet
            else {
                head = head->next;
                root = head;
                // if head is not the last elemnt
                if(head) {
                    head->prev = nullptr;
                }
            }
        }
        else {
            head = head->next;
        }
    }
    return root;
}