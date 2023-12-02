bool isLeaf(Node* root) {
    return (!root->left && !root->right);
}

bool isParentSum(Node *root){
    if(!root || isLeaf(root)) return true;
    int sum = 0;
    if(root->left) {
        sum += root->left->data;
    }
    if(root->right) {
        sum += root->right->data;
    }
    if(sum != root->data) return false;
    return isParentSum(root->left) && isParentSum(root->right);
}