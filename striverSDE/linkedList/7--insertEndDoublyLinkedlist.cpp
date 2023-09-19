/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    Node *node = new Node(k);
    if(!head) {
        return node;
    }
    Node *root = head;
    while(head && head->next) {
        head = head->next;
    }
    node->prev = head;
    head->next = node;
    return root;
}
