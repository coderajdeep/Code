// leetcode 145

// recursive solution

class Solution {
public:
    
    void postorder(TreeNode *root, vector<int>&ans) {
        if(!root) {
            return;
        }
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        vector<int>ans;
        postorder(root, ans);
        return ans;
    }
};



// iterative solution
// two stack (actually one stack and vector.. vector need to be revrerse at the end)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) {
            return vector<int>{};
        }
        
        vector<int>ans;
        stack<TreeNode*>s;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode *curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            
            if(curr->left) {
                s.push(curr->left);
            }
            if(curr->right) {
                s.push(curr->right);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};



// using only one stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        
        stack<TreeNode*>s;
        TreeNode *curr = root, *temp = nullptr;
        
        while(!s.empty() || curr) {
            if(curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                temp = s.top()->right;
                
                if(!temp) {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    
                    // this is needed when we want to print the root of any subtree (root is printed at the end of any subtree)
                    while(!s.empty() && temp==(s.top()->right)) {
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};

