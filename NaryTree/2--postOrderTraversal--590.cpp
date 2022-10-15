// leetcode 590
class Solution {
public:
    void dfs(Node* root, vector<int> &ans) {
        ans.push_back(root->val);
        int n = root->children.size();
        for(int i=n-1; i>=0; i--) dfs(root->children[i], ans);
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int>ans;
        dfs(root, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};