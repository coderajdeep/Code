// Leetcode 257
// Generate all root to leaf paths

// This solution handles when we need to return vector<vector<int>>
class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        if(root && !root->left && !root->right) return true;
        return false;
    }
    
    void dfs(TreeNode *root, vector<int> &ds, vector<vector<int>> &ans) {
        if(!root) return;
        
        ds.push_back(root->val);
        
        if(isLeaf(root)) {
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        dfs(root->left, ds, ans);
        dfs(root->right, ds, ans);
        ds.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int>ds;
        dfs(root, ds, ans);
        vector<string>str;
        for(auto arr:ans) {
            string s;
            for(int x:arr) {
                if(!s.empty())
                    s += "->";
                s += to_string(x);
            }
            str.push_back(s);
        }
        return str;
    }
};