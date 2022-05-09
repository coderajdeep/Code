// leetcode - 98

// best approach

class Solution {
public:
    
    bool dfs(TreeNode *root, long minVal, long maxVal) {
        if(!root) {
            return true;
        }
        return (root->val > minVal) and (root->val < maxVal) and dfs(root->left, minVal, root->val) and dfs(root->right, root->val, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};

// inorder trversal and store value in array

class Solution {
public:
    
    void dfs(TreeNode *root, vector<int> &arr) {
        if(!root) {
            return;
        }
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        
        vector<int>arr;
        dfs(root, arr);
        int n = arr.size();
        
        for(int i=0; i<n-1; ++i) {
            if(arr[i]>=arr[i+1]) {
                return false;
            }
        }
        return true;
    }
};

// inorder traversal with space optimization
// failed for this test case
// [-2147483648,null,2147483647]

class Solution {
public:
    
    // inorder traversal space optimized
    
    bool dfs(TreeNode *root, int &prev) {
        if(!root) {
            return true;
        }
        
        if(dfs(root->left, prev)==false) {
            return false;
        }
        
        if(prev>=root->val) {
            return false;
        }
        
        prev = root->val;
        
        return dfs(root->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root or (!root->left and !root->right)) {
            return true;
        }
        
        int prev = INT_MIN;
        
        return dfs(root, prev);
    }
};