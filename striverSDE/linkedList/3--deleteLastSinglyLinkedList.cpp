// Delete last node of singly linked list -- coding ninjas

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    if(!list) return list;
    if(list && !list->next) return nullptr;
    Node *prev = nullptr, *root = list;
    while(list && list->next) {
        prev = list;
        list = list->next;
    }
    prev->next = nullptr;
    return root;
}