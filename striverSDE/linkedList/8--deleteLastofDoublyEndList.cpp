// delete last of doubly linked list

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    if(!head) return head;
    Node *root = head;
    while(head && head->next) {
        head = head->next;
    }
    Node *prev = head->prev;
    if(prev) {
        prev->next = nullptr;
    }
    else {
        root = nullptr;
    }
    return root;
}
