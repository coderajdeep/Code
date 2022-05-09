// leetcode - 236


// Best approach
// p, q must present in Binary Tree
// or both can not present
// but if obly p or only q is present then this will not work

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }
        if(root==p or root==q) {
            return root;
        }
        
        TreeNode *node1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *node2 = lowestCommonAncestor(root->right, p, q);
                
        if(node1 and node2) {
            return root;
        }
        // node2 == null means if node1 == p then q will be decendents
        if(node1) {
            return node1;
        }
        return node2;
        // node1 == null means if node2 == p then q will be decendents
    }
};



// Time Complexity O(n)
// Space complexity O(n)

class Solution {
public:

    // any of the dfs will work fine

    // this will store the value in root to target order
    bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode*> &arr) {
        if(!root) {
            return false;
        }
        
        arr.push_back(root);
        
        if(root==target or dfs(root->left, target, arr) or dfs(root->right, target, arr)) {
            return true;
        }
        arr.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }
        vector<TreeNode*>arr1, arr2;
        if(dfs(root, p, arr1) and dfs(root, q, arr2)) {
            int n1 = arr1.size();
            int n2 = arr2.size();
            TreeNode *prev = nullptr;
            int i = 0, j = 0;
            while(i<n1 and j<n2) {
                if(arr1[i]==arr2[j]) {
                    prev = arr1[i];
                }
                else {
                    return prev;
                }
                ++i;
                ++j;
            }
            return prev;
        }
        return nullptr;
    }
};




// another solution

class Solution {
public:
    
    // this will store the value in target to root order
    bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode*> &arr) {
        if(!root) {
            return false;
        }
        
        if(root==target or dfs(root->left, target, arr) or dfs(root->right, target, arr)) {
            arr.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return root;
        }
        
        vector<TreeNode*>arr1, arr2;
        
        if(dfs(root, p, arr1) and dfs(root, q, arr2)) {
            int n1 = arr1.size();
            int n2 = arr2.size();
            
            int i=n1-1, j=n2-1;
            TreeNode *prev = nullptr;
            
            while(i>=0 and j>=0) {
                if(arr1[i]==arr2[j]) {
                    prev = arr1[i];
                }
                else {
                    return prev;
                }
                --i;
                --j;
            }
            return prev;
        }
        return nullptr;
    }
};