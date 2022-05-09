// leetcode 700
// https://techiedelight.com/practice/?id=_YWt
// https://techiedelight.com/practice/?id=n7yZ

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(!root or root->val == val) {
            return root;
        }
        
        if(val > root->val) {
            return searchBST(root->right, val);
        }
        
        return searchBST(root->left, val);
        
    }
};

// iterative solution

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root) {
            if(val == root->val) {
                return root;
            }
            else if(val > root->val) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return nullptr;
    }
};


// geeks version

bool search(Node* root, int x) {
    // Your code here
    if(!root) {
        return false;
    }
    
    if(root->data==x) {
        return true;
    }
    
    if(x > root->data) {
        return search(root->right, x);
    }
    
    return search(root->left, x);
}

// iterative version

bool search(Node* root, int x) {
    // Your code here
    while(root) {
        if(x == root->data) {
            return true;
        }
        else if(x > root->data) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return false;
}
