// Time complexity O(n)
// Space complexity O(h) : recursion stack space
// Best approach
// https://youtu.be/_-QHfMDde90?si=WTxWEKm6m5Qp4iV6
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return nullptr;
    if(root==p) return p;
    if(root==q) return q;
    TreeNode* lnode = lowestCommonAncestor(root->left, p, q);
    TreeNode* rnode = lowestCommonAncestor(root->right, p, q);
    if(!lnode) return rnode;
    if(!rnode) return lnode;
    else return root;
}

// Time Complexity O(2*n)
// Space complexity O(2*n)
void dfs(TreeNode* root, vector<vector<TreeNode*>>& paths, vector<TreeNode*>& path, TreeNode* p, TreeNode* q) {
    if(!root) return;
    path.push_back(root);
    if(root==p || root==q) {
        paths.push_back(path);
    }
    dfs(root->left, paths, path, p, q);
    dfs(root->right, paths, path, p, q);
    path.pop_back();
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;
    vector<vector<TreeNode*>> paths;
    vector<TreeNode*> path;
    dfs(root, paths, path, p, q);
    int n = paths[0].size();
    int m = paths[1].size();
    if(n==1 || m==1) return root;
    int i = 0, j = 0;
    while(i<n && j<m) {
        if(paths[0][i]!=paths[1][j]) {
            return paths[0][i-1];
        }
        else if(paths[0][i]==q) {
            return q;
        }
        else if(paths[1][j]==p) {
            return p;
        }
        ++i;
        ++j;
    }
    return root;
}



// Time complexity O(n2)
// Space complexity O(h2)
// Coding Ninjas
bool isNodeExist(TreeNode<int> *root, int node) {
    if(!root) return false;
    if(root->data == node) return true;
    return (isNodeExist(root->left, node) || isNodeExist(root->right, node));
}

bool postOrder(TreeNode<int> *root, int& ans, int x, int y) {
    if(!root) return false;
    if(postOrder(root->left, ans, x, y) || postOrder(root->right, ans, x, y)) {
        return true;
    }
    if(isNodeExist(root, x) && isNodeExist(root, y)) {
        ans = root->data;
        return true;
    }
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(!root) return -1;
    int ans = -1;
    postOrder(root, ans, x, y);
    return ans;
}