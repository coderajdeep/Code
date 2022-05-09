// leetcode 144

// recursive solution

class Solution {
public:
    
    void preorder(TreeNode *root, vector<int>&ans) {
        if(!root) {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        
        vector<int>ans;
        preorder(root, ans);
        
        return ans;
    }
};


// iterative solution

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        
        stack<TreeNode*>s;
        s.push(root);
        vector<int>ans;
        
        while(!s.empty()) {
            TreeNode *curr = s.top();
            s.pop();
            
            ans.push_back(curr->val);
            
            if(curr->right) {
                s.push(curr->right);
            }
            if(curr->left) {
                s.push(curr->left);
            }
        }
        return ans;
    }
};