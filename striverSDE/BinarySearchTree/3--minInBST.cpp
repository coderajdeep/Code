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

// Recursive solution
bool findMin(Node* root, int &min) {
    if(!root) return false;
    if(findMin(root->left, min)) return true;
    min = root->data;
    return true;
}
int minVal(Node* root){
    int min;
	bool val = findMin(root, min);
    if(val) return min;
    return -1;
}