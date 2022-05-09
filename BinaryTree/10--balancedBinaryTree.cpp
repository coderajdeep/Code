// recursive O(n) solution
// leetcode 110

class Solution {
public:
    
    // whenever first unbalance occured 
    // this method will start to return -1 to its previous function call
    
    int height(TreeNode *root) {
        if(!root)
            return 0;
        int l = height(root->left);
        if(l==-1)
            return -1;
        int r = height(root->right);
        if(r==-1)
            return -1;
        if(abs(l-r)>1)
            return -1;
        return (max(l, r) + 1);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(height(root)==-1)
            return false;
        return true;
    }
};