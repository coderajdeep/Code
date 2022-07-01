// geeks
// https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/

// best dfs solution


/*
    Algorithm

    root == NULL ==> return true
    root == leaf ==> return true

    sum = 0

    if left != leaf ==> sum += ( 2 * left )
    if left == leaf ==> sum += left

    similarly

    if right != leaf ==> sum += ( 2 * right)
    if right == leaf ==> sum += right
*/

class solution {
    public:
    
    bool isLeaf(Node *root) {
        return (root and !root->left and !root->right) ? true : false ;
    }
    
    bool isSumTree(Node* root)
    {
        if(!root) {
            return true;
        }
        if(isLeaf(root)) {
            return true;
        }
        
        int sum = 0;
        
        if(root->left) {
            
            if(isLeaf(root->left)) {
                
                sum += (root->left->data);
            }
            
            else {
                
                sum += (2 * (root->left->data));
            }
        }
        
        if(root->right) {
            
            if(isLeaf(root->right)) {
                
                sum += (root->right->data);
            }
            
            else {
                
                sum += (2 * (root->right->data));
            }
        }
        
        return (root->data == sum) and isSumTree(root->left) and isSumTree(root->right);
    }
};


// same as above approach
// https://www.codingninjas.com/codestudio/problems/check-if-binary-tree-is-sum-tree-or-not_1164404
bool isSumTree(TreeNode<int> *root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    int sum = 0;
    if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
    else if(root->left) sum += 2 * root->left->val;
    if(root->right && !root->right->left && !root->right->right) sum += root->right->val;
    else if(root->right) sum += 2 * root->right->val;
    return (sum == root->val) && isSumTree(root->left) && isSumTree(root->right);
}


// Calculating left and right subtree sum in one go
// Time complexity O(n)

bool isLeaf(TreeNode<int> *root) {
    return (root && !root->left && !root->right) ? true : false;
}

int solve(TreeNode<int> *root, bool &ans) {
    if(!root || !ans) return 0;
    int l = solve(root->left, ans);
    int r = solve(root->right, ans);
    if(!isLeaf(root) && (root->val != l+r)) ans = false;
    return root->val + l + r;
} 

bool isSumTree(TreeNode<int> *root)
{
    if(!root) return true;
    bool ans = true;
    solve(root, ans);
    return ans;
}


// another staright forward approach

class Solution
{
    public:
    
    int treeSum(Node *root, bool &flag) {
        if(!root) {
            return 0;
        }
        int lsum = treeSum(root->left, flag);
        int rsum = treeSum(root->right, flag);
        
        if((root->left or root->right) and root->data != (lsum + rsum)) {
            flag = false;
        }
        
        return (root->data + lsum + rsum);
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         if(!root) {
             return true;
         }
         
         bool flag = true;
         treeSum(root, flag);
         
         return flag;
    }
};