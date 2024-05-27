// Invert Binary Tree -- leetcode 226s
// Time complexity O(n)
// Space complexity O(h) : recursive space complexity h --> height of the tree
TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    
    swap(root->left, root->right);
    
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    
    root->left = l;
    root->right = r;

    return root;
}

// Iterative approach
TreeNode* invertTree(TreeNode* root) {
    if(!root) {
        return root;
    }
    
    stack<TreeNode*>s;
    s.push(root);
    
    while(!s.empty()) {
        TreeNode *curr = s.top();
        s.pop();
        
        if(curr->right) {
            s.push(curr->right);
        }
        if(curr->left) {
            s.push(curr->left);
        }
        
        swap(curr->right, curr->left);
    }
    
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) {
        return root;
    }
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty()) {
        TreeNode *curr = s.top();
        s.pop();
        swap(curr->right, curr->left);
        if(curr->right) {
            s.push(curr->right);
        }
        if(curr->left) {
            s.push(curr->left);
        }
    }
    
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    
    swap(root->left, root->right);
    
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    
    root->left = l;
    root->right = r;

    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    
    root->left = l;
    root->right = r;

    swap(root->left, root->right);

    return root;
}

// Geeks
void mirror(Node* node) {
    if(!node) return;
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}