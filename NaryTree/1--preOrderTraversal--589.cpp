// leetcode 589
class Solution {
public:
    void dfs(Node* root, vector<int> &ans) {
        ans.push_back(root->val);
        int n = root->children.size();
        
        for(int i=0; i<n; ++i) dfs(root->children[i], ans);
    }
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};