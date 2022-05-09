// geeks


class Solution{
  public:
    
    // inorder, preorder or postorder any of them will work
    void dfs(Node *root, int level, map<int, int>&m) {
        if(!root) {
            return;
        }
        m[level] += root->data;
        dfs(root->left, level-1, m);
        dfs(root->right, level+1, m);
    }
  
    vector <int> verticalSum(Node *root) {
        // add code here.
        if(!root) {
            return {};
        }
        map<int, int>m;
        dfs(root, 0, m);
        vector<int>ans(m.size());
        int index = 0;
        
        for(auto val:m) {
            ans[index++] = val.second;
        }
        return ans;
    }
};