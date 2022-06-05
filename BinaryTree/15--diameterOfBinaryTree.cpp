// leetcode 543
// leetcode answer is less than one from geeks answer
// leetcode counts edge
// geeks count nodes
// Time O(n)

class Solution {
public:
    
    int height(TreeNode *root, int &ans) {
        if(!root) {
            return 0;
        }
        
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        
        ans = max(ans, (lh + rh));
        
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        int ans = 0;
        height(root, ans);
        return ans;
    }
};

// Time O(n2)
class Solution {
public:
    
    int height(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        
        return max({ld, rd, lh+rh});
    }
};


// geeks solution

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int height(Node *root, int &ans) {
        if(!root) {
            return 0;
        }
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        
        // here considering number of nodes in the path
        ans = max(ans, 1+lh+rh);
        
        return 1 + max(lh, rh);
    }
    
    int diameter(Node* root) {
        // Your code here
        if(!root) {
            return 0;
        }
        
        int ans = 0;
        height(root, ans);
        return ans;
    }
};