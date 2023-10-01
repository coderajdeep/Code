// Remove duplicate nodes from sorted doubly linkedlist -- coding ninjas

// Time complexity O(n)
// Space complexity O(1)
Node * removeDuplicates(Node *head)
{
    while(head && head->next && head->data==head->next->data) {
        head = head->next;
    }
    if(!head || !head->next) {
        return head;
    }
    Node *root = head;
    while(head && head->next) {
        if(head->data == head->next->data) {
            Node *temp = head->next;
            head->next = temp->next;
            if(temp->next) {
                temp->next->prev = head;
            }
        }
        else {
            head = head->next;
        }
    }
    return root;
}