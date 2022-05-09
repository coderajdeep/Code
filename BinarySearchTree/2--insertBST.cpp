// leetcode 701
// https://techiedelight.com/practice/?id=OIYZ

// best recursive

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }
        else if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        else if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

// best iterative

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *temp = new TreeNode(val);
        TreeNode *curr = root, *parent = nullptr;
        
        while(curr) {
            parent = curr;
            if(val > curr->val) {
                curr = curr->right;
            }
            else if(val < curr->val) {
                curr = curr->left;
            }
            else {
                return root; // if val exist in BST
            }
        }
        if(!parent) {
            return temp; // if root is empty
        }
        if(val < parent->val) {
            parent->left = temp;
        }
        else {
            parent->right = temp;
        }
        return root;
    }
};


// same solution
// just root == nullptr handle saperately

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *temp = new TreeNode(val);
        
        if(!root) {
            return temp;
        }
        
        TreeNode *parent = nullptr, *curr = root;
        
        while(curr) {
            parent = curr;
            if(val > curr->val) {
                curr = curr->right;
            }
            else if(val < curr->val) {
                curr = curr->left;
            }
        }
        
        if(val < parent->val) {
            parent->left = temp;
        }
        else if(val > parent->val) {
            parent->right = temp;
        }
        return root;
    }
};


// iterative method

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *temp = new TreeNode(val);
        
        if(!root) {
            root = temp;
            return root;
        }
        
        TreeNode *r = root, *prev = NULL;
        bool left = true;
        
        while(r) {
            if(val == r->val) {
                break;
            }
            if(val > r->val) {
                left = false;
                prev = r;
                r = r->right;
            }
            else {
                left = true;
                prev = r;
                r = r->left;
            }
        }
        if(!r) {
            if(left) {
                prev->left = temp;
            }
            else {
                prev->right = temp;
            }
        }
        return root;
    }
};

// recursive solution

class Solution {
public:
    
    void insertKey(TreeNode *root, TreeNode* &prev, bool &left, int key) {
        
        if(!root) {
            
            TreeNode *temp = new TreeNode(key);
            
            if(!prev) {
                root = temp;
            }
            else if(left) {
                prev->left = temp;
            }
            else {
                prev->right = temp;
            }
        }
        
        else if(key == root->val) {
            return;
        }
        
        else if(key > root->val) {
            left = false;
            prev = root;
            insertKey(root->right, prev, left, key);
        }
        else {
            left = true;
            prev = root;
            insertKey(root->left, prev, left, key);
        }
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode *temp = new TreeNode(val);
            root = temp;
            return root;
        }
        TreeNode *prev = NULL;
        bool left = false;
        insertKey(root, prev, left, val);
        return root;
    }
};