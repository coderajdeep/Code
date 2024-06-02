// Time complexity O(h)

int minValue(Node* root) {
    int val = INT_MAX;
    while(root) {
        val = min(root->data, val);
        root = root->left;
    }
    return val;
}

// Recursive solution
int minValue(Node* root) {
    if(!root) return INT_MAX;
    if(!root->left) return root->data;
    return minValue(root->left);
}