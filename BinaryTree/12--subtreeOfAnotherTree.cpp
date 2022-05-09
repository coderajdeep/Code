// leetcode 572

// Time O(n*m)
// need to improve time complexity

// recursive approach

class Solution {
public:
    
    bool isSame(TreeNode *t1, TreeNode *t2) {
        if(!t1 and !t2) {
            return true;
        }
        if(!t1 or !t2) {
            return false;
        }
        return ((t1->val == t2->val) and isSame(t1->left, t2->left) and isSame(t1->right, t2->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) {
            return true;
        }
        if(!root) {
            return false;
        }
        if(isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};