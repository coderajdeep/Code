// Time complexity O((logn)*(logn))
// Space complexity O(logn)

int leftHeight(TreeNode* root) {
    if(!root) return 0;
    int height = 0;
    while(root) {
        ++height;
        root = root->left;
    }
    return height;
}
int rightHeight(TreeNode* root) {
    if(!root) return 0;
    int height = 0;
    while(root) {
        ++height;
        root = root->right;
    }
    return height;
}
// A full binary tree is a binary tree in which all of the nodes have either 0 or 2 offspring. In other terms, a full binary tree is a binary tree in which all nodes, except the leaf nodes, have two offspring.
// A perfect binary tree is a special type of binary tree in which all the leaf nodes are at the same depth, and all non-leaf nodes have two children. In simple terms, this means that all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.
// A binary tree is said to be a complete binary tree if all its levels, except possibly the last level, have the maximum number of possible nodes, and all the nodes in the last level appear as far left as possible.
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int lheight = leftHeight(root->left);
    int rheight = rightHeight(root->right);
    if(lheight==rheight) {
        return (1<<(lheight+1)) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}