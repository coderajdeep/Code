// leetcode 222


// Time complexity O(logn * logn)

class Solution {
public:
    
    int power(int x) {
        int ans = 1;
        for(int i=1; i<=x; ++i) {
            ans *= 2;
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int lh = 0, rh = 0;
        TreeNode *curr = root;
        
        while(curr) {
            ++lh;
            curr = curr->left;
        }
        
        curr = root;
        
        while(curr) {
            ++rh;
            curr = curr->right;
        }
        
        if(lh==rh) {
            return (power(lh)-1);
            // return ((1<<lh) - 1);
            // this will be better
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};