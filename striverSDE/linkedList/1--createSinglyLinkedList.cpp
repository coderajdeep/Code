// Create a singly linkedlist from vector -- coding ninja

/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    int n = arr.size();
    if(n==0) return nullptr;
    Node *root = new Node(arr[0]);
    Node *head = root;
    for(int i=1; i<n; ++i) {
        head->next = new Node(arr[i]);
        head = head->next;
    }
    return root;
}