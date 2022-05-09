// leetcode 112
// Path Sum

class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        return (!root->left and !root->right) ? true : false ;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return false;
        }
        if(root->val==targetSum and isLeaf(root)) {
            return true;
        }
        
        return (hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val));
    }
};

// below solution will take more time

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(root->val==targetSum && (!root->left && !root->right))
            return true;
        bool l = hasPathSum(root->left, targetSum-(root->val));
        bool r = hasPathSum(root->right, targetSum-(root->val));
        // if l == true
        // still it will wait for r to calculate
        return l || r;
    }
};