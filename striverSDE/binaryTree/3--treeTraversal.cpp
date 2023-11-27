// Binary Tree traversal

void inOrder(TreeNode* root, vector<int>& inorder) {
    if(!root) return;
    inOrder(root->left, inorder);
    inorder.push_back(root->data);
    inOrder(root->right, inorder);
}
void preOrder(TreeNode* root, vector<int>& preorder) {
    if(!root) return;
    preorder.push_back(root->data);
    preOrder(root->left, preorder);
    preOrder(root->right, preorder);
}
void postOrder(TreeNode* root, vector<int>& postorder) {
    if(!root) return;
    postOrder(root->left, postorder);
    postOrder(root->right, postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    if(!root) vector<vector<int>> {};
    vector<vector<int>> ans;
    vector<int> inorder, preorder, postorder;
    inOrder(root, inorder);
    preOrder(root, preorder);
    postOrder(root, postorder);
    return {inorder, preorder, postorder};
}