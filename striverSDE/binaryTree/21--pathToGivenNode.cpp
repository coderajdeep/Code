// Time complexity O(n)
// Space Complexity O(h) : h --> height of binary tree
// https://www.interviewbit.com/problems/path-to-given-node/

bool utils(TreeNode* A, int B, vector<int>& ans) {
    if(!A) return false;
    ans.push_back(A->val);
    if(A->val==B) return true;
    if(utils(A->left, B, ans) || utils(A->right, B, ans)) {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    if(!A) return vector<int> {};
    vector<int> ans;
    utils(A, B, ans);
    return ans;
}