// Time complexity O(h)

int minVal(Node* root){
	if(!root) return -1;
    Node* node = root;
    Node* prev = nullptr;
    while(node) {
        prev = node;
        node = node->left;
    }
    return prev->data;
}