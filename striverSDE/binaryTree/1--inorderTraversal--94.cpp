// leetcode 94
// Inorder traversal

// Time complexity O(n)
// Space complexity O(n)
// Recursive way
void inorderUtils(TreeNode* root, vector<int>& ans) {
    if(!root) return;
    inorderUtils(root->left, ans);
    ans.push_back(root->val);
    inorderUtils(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorderUtils(root, ans);
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
// Iterative approach
vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return {};
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* curr = root;
    while(curr || !st.empty()) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}