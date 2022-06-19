// leetcode 107

// Calculating height initially
class Solution {
public:
    
    int height(TreeNode *root) {
        return (root ? (1 + max(height(root->left), height(root->right))) : 0);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        int h = height(root);
        vector<vector<int>> ans(h);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int>arr(size);
            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                arr[i] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans[--h] = arr; 
        }
        return ans;
    }
};


// reversing the answer array
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {
            
            int t = q.size();
            vector<int>temp;
            
            for(int i=0; i<t; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                
                temp.push_back(curr->val);
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};