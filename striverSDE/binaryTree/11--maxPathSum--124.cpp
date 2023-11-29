// Time complexity O(n)
// Space complexity O(h) : h--> tree height
// Recursion stack space

int maxPathSumUtils(TreeNode* root, int& maxSum) {
    if(!root) return 0;
    int lsum = max(0, maxPathSumUtils(root->left, maxSum));
    int rsum = max(0, maxPathSumUtils(root->right, maxSum));
    maxSum = max(maxSum, (root->val + lsum + rsum));
    return (root->val + max(lsum, rsum));
}
int maxPathSum(TreeNode* root) {
    if(!root) return 0;
    int maxSum = INT_MIN;
    maxPathSumUtils(root, maxSum);
    return maxSum;
}