// Is BT a valid BST
// Time complexity O(n)
// Space complexity O(h) : considering recursive stack space

bool isBSTValid(TreeNode *root, long leftValue, long rightValue) {
    if(!root) return true;
    // We can check this in the next line also
    if((root->val)<=leftValue || (root->val)>=rightValue) return false;
    return isBSTValid(root->left, leftValue, root->val) && isBSTValid(root->right, root->val, rightValue);
    // return (root->val)>leftValue && (root->val)<rightValue && isBSTValid(root->left, leftValue, root->val) 
    // && isBSTValid(root->right, root->val, rightValue);
}
bool isValidBST(TreeNode* root) {
    return isBSTValid(root, LONG_MIN, LONG_MAX);
}