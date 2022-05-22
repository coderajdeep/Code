// leetcode 94

// recursive solution

class Solution {
public:
    
    void inorder(TreeNode *root, vector<int>&ans) {
        if(!root) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) {
            return vector<int>{};
        }
        
        vector<int>ans;
        inorder(root, ans);
        return ans;
    }
};



// iterative solution

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) {
            return vector<int>{};
            // return {}
            // both are same
        }
        
        vector<int>ans;
        stack<TreeNode*>s;
        TreeNode *curr = root;
        
        while(curr or !s.empty()) {
            if(curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                s.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};