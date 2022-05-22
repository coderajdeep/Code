// DeepestLeavesSum
// Leetcode 1302

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Using unordered_map
 // dfs
class Solution {
public:
    
    int height(TreeNode *root, int level, unordered_map<int, int> &m) {
        if(!root) return 0;
        m[level] += root->val;
        return 1 + max(height(root->left, level+1, m), height(root->right, level+1, m));
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        unordered_map<int, int> m;
        int level = 1;
        int h = height(root, level, m);
        return m[h];
    }
};

// Level order traversal using queue
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum;
        while(!q.empty()) {
            int t = q.size();
            sum = 0;
            while(t--) {
                auto p = q.front();
                q.pop();
                sum += p->val;
                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
            }
        }
        return sum;
    }
};

// dfs
// calculating height previously and then find sum in a particular height using dfs
class Solution {
public:
    int height(TreeNode *root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void dfs(TreeNode *root, int level, int &sum) {
        if(!root) return;
        if(level==1) {
            sum += root->val;
            return;
        }
        dfs(root->left, level-1, sum);
        dfs(root->right, level-1, sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int h = height(root);
        int sum = 0;
        dfs(root, h, sum);
        return sum;
    }
};