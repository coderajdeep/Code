// leetcode 226

// recursive
// preorder
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        swap(root->left, root->right);
        TreeNode *l = invertTree(root->left);
        TreeNode *r = invertTree(root->right);
        root->left = l;
        root->right = r;
        return root;
    }
};

// recursive
// postorder
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *l = invertTree(root->left);
        TreeNode *r = invertTree(root->right);
        root->left = l;
        root->right = r;
        swap(root->left, root->right);
        return root;
    }
};

// leetcode discussion
// recursive
TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}

// iterative
// preorder
class Solution {
public:
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
};

//leetcode discussion
// iterative
TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}

// recursive solution - preorder traversal

class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        return (root->left==nullptr and root->right==nullptr) ? true : false;
    }
    
    // doing pre-order traversal
    void dfs(TreeNode *root) {
        if(!root or isLeaf(root)) {
            return;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root or isLeaf(root)) {
            return root;
        }
        
        dfs(root);
        
        return root;
    }
};

// recursive post order

class Solution {
public:
    
    // doing post-order traversal
    void dfs(TreeNode *root) {
        if(!root) {
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return root;
        }
        
        dfs(root);
        
        return root;
    }
};