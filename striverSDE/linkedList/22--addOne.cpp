// Will do recursive and stack solution later

Node *reverseLinkedlist(Node *head) {
    if(!head || !head->next) {
        return head;
    }
    Node *curr = head, *prev = nullptr, *nxt = nullptr;
    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
Node *addOne(Node *head)
{
    Node *revHead = reverseLinkedlist(head);
    Node *prev = nullptr, *revHeadCopy = revHead;
    int prevNum = 1, num;
    while(revHead) {
        num = revHead->data + prevNum;
        if(num<10) {
            revHead->data = num;
            break;
        }
        else {
            revHead->data = num%10;
            prevNum = 1;
        }
        prev = revHead;
        revHead = revHead->next;
    }
    if(prevNum!=0 && !revHead) {
        prev->next = new Node(prevNum);
    }
    head = reverseLinkedlist(revHeadCopy);
    return head;
}
