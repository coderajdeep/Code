// Create doubly linked list

/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) {
    int n = arr.size();
    if(n==0) return nullptr;
    Node *root = new Node(arr[0]);
    Node *head = root;
    for(int i=1; i<n; ++i) {
        Node *node = new Node(arr[i]);
        head->next = node;
        node->prev = head;
        head = node;
    }
    root->prev = nullptr;
    return root;
}
