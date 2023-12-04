// Time complexity O(h)
// Space complexity O(h)

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) {
        return new TreeNode(val);
    }
    else if(val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    else if(val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Iterative Method
// Time complexity O(h)
// Space complexity O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode *prev = nullptr, *node = root;
    bool isLeft = false;
    while(root && root->val!=val) {
        prev = root;
        if(root->val>val) {
            root = root->left;
            isLeft = true;
        }
        else {
            root = root->right;
            isLeft = false;
        }
    }
    if(isLeft) {
        prev->left = new TreeNode(val);
    }
    else {
        prev->right = new TreeNode(val);
    }
    return node;
}

// Striver iterative
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode* curr = root;
    while(true) {
        if(curr->val > val) {
            if(curr->left) {
                curr = curr->left;
            }
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
        else {
            if(curr->right) {
                curr = curr->right;
            }
            else {
                curr->right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}