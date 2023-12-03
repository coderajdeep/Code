// Time complexity O(n2)
// Space complexity O(n)

TreeNode* getTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postEnd) {
    if(inStart>inEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postEnd--]);
    int inIndex;
    for(int i=inStart; i<=inEnd; ++i) {
        if(inorder[i]==root->val) {
            inIndex = i;
            break;
        }
    }
    root->right = getTree(inorder, postorder, inIndex+1, inEnd, postEnd);
    root->left = getTree(inorder, postorder, inStart, inIndex-1, postEnd);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int inStart = 0;
    int inEnd = inorder.size()-1;
    int postEnd = postorder.size()-1;
    TreeNode* root = getTree(inorder, postorder, inStart, inEnd, postEnd);
    return root;
}

// Optimized approach
// Time complexity O(n)
// Space complexity  O(n)

TreeNode* getTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &inHash, int inStart, int inEnd, int &postEnd) {
    if(inStart>inEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postEnd--]);
    int inIndex;
    for(int i=inStart; i<=inEnd; ++i) {
        if(inorder[i]==root->val) {
            inIndex = i;
            break;
        }
    }
    root->right = getTree(inorder, postorder, inHash, inIndex+1, inEnd, postEnd);
    root->left = getTree(inorder, postorder, inHash, inStart, inIndex-1, postEnd);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int inStart = 0;
    int inEnd = inorder.size()-1;
    int postEnd = postorder.size()-1;
    unordered_map<int, int> inHash;
    for(int i=inStart; i<=inEnd; ++i) {
        inHash[inorder[i]] = i;
    }
    TreeNode* root = getTree(inorder, postorder, inHash, inStart, inEnd, postEnd);
    return root;
}