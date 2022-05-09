// leetcode 101


class Solution {
public:
    
    bool areMirror(TreeNode *t1, TreeNode *t2) {
        if(!t1 and !t2) {
            return true;
        }
        if(!t1 or !t2) {
            return false;
        }
        return ((t1->val==t2->val) and areMirror(t1->left, t2->right) and areMirror(t1->right, t2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        return areMirror(root->left, root->right);
    }
};



// https://www.techiedelight.com/check-given-binary-tree-symmetric-structure-not/

// Function to check if subtree rooted at `X` and `Y` mirror each other
bool areMirror(Node* X, Node* Y)
{
    // base case: if both trees are empty
    if (X == nullptr && Y == nullptr) {
        return true;
    }
 
    // return true if
    // 1. Both trees are non-empty, and
    // 2. The left subtree is the mirror of the right subtree, and
    // 3. The right subtree is the mirror of the left subtree
    return (X != nullptr && Y != nullptr) &&
        areMirror(X->left, Y->right) &&
        areMirror(X->right, Y->left);
}
 
// Function to check if a given binary tree has a symmetric structure or not
bool isSymmetric(Node* root)
{
    // base case
    if (root == nullptr) {
        return true;
    }
 
    // return true if left and right subtree mirror each other
    return isSymmetric(root->left, root->right);
}