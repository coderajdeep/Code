// leetcode - 102

// best solution

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp(size);
            
            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                
                temp[i] = curr->val;
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

// iterative solution using queue

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return vector<vector<int>>{};
        }
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        
        while(!q.empty()) {
            
            int size = q.size();
            vector<int>temp;
            
            while(size--) {
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
        return ans;
    }
};


// recursive solution
// time O(n2)

class Solution {
public:
    
    bool dfs(TreeNode *root, int level, vector<int> &arr) {
        if(!root) {
            return false;
        }
        if(level==1) {
            arr.push_back(root->val);
            return true;
        }
        bool l = dfs(root->left, level-1, arr);
        bool r = dfs(root->right, level-1, arr);
        
        return (l || r);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return vector<vector<int>>{};
        }
        
        int height = 1;
        vector<int>arr;
        vector<vector<int>>ans;
        
        while(dfs(root, height, arr)) {
            ans.push_back(arr);
            arr.clear();
            height += 1;
        }
        
        return ans;
    }
};


// Using unordered_map

class Solution {
public:
    
    int dfs(TreeNode *root, int level, unordered_map<int, vector<int>> &umap) {
        if(!root) return 0;
        umap[level].push_back(root->val);
        int l = dfs(root->left, level+1, umap);
        int r = dfs(root->right, level+1, umap);
        return 1 + max(l, r);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        unordered_map<int, vector<int>> umap;
        int height = dfs(root, 1, umap);
        vector<vector<int>>ans(height);
        for(int i=1; i<=height; ++i) {
            ans[i-1] = umap[i];
        }
        return ans;
    }
};