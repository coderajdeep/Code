// Leetcode 1609
// This can be solved using left to right (BFS) - this will be more easier
// This can be solved recursive way


// Recursive solution (DFS) using extra space (unordered_map)
class Solution {
public:
    
    bool dfs(TreeNode *root, int level, unordered_map<int, int> &mp) {
        if(!root) return true;
        int value = root->val;
        if(((level+1)%2)!=(value%2)) return false; 
        if(mp.find(level)!=mp.end()) {
            if(level%2==0 && mp[level]>=value) return false;
            if(level%2==1 && mp[level]<=value) return false;
        }
        mp[level] = value;
        int l = dfs(root->left, level+1, mp);
        if(!l) return false;
        int r = dfs(root->right, level+1, mp);
        return (l && r);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        unordered_map<int, int> mp;
        return dfs(root, 0, mp);
    }
};


// Traverse through left to right (BFS)
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool isEven = true;
        int prev;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                int value = curr->val;
                
                if(isEven) {
                    if(value%2==0) return false;
                    if(i && (prev>=value)) return false;
                }
                else {
                    if(value%2==1) return false;
                    if(i && (prev<=value)) return false;
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                prev = value;
            }
            isEven = isEven ? false : true;
        }
        return true;
    }
};


// Traverse through right to left
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool isEven = true;
        int prev;
        
        while(!q.empty()){
            int t = q.size();
            for(int i=t-1; i>=0; --i) {
                TreeNode *curr = q.front();
                int value = curr->val;
                q.pop();
                if(isEven) {
                    if(value%2==0) return false;
                    if(i!=t-1 && (value>=prev)) return false; 
                }
                else {
                    if(value%2==1) return false;
                    if(i!=t-1 && (value<=prev)) return false;
                }
                prev = value;
                
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
            }
            isEven = isEven ? false : true;
        }
        return true;
    }
};