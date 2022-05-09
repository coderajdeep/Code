// leetcode 450
// very very important
// recursive solution

class Solution {
public:
    
    TreeNode* getSucc(TreeNode *root) {
        root = root->right;
        while(root and root->left) {
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) {
            return root;
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if(root->left==nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode *succ = getSucc(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};