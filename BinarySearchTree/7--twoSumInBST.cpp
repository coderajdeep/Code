// leetcode 653


// Time O(n) ; Space O(n+h) 
// Here we are using array

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
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        
        vector<int>arr;
        dfs(root, arr);
        
        int i = 0, j = arr.size()-1;
        
        while(i<j) {
            
            int sum = arr[i] + arr[j];
            
            if(sum==k) {
                return true;
            }
            if(sum>k) {
                --j;
            }
            else {
                ++i;
            }
        }
        return false;
    }
};

// using unordered_set

class Solution {
public:
    
    bool dfs(TreeNode *root,int sum, unordered_set<int> &s) {
        if(!root) {
            return false;
        }
        if(dfs(root->left, sum, s)) {
            return true;
        }
        if(s.find(sum-root->val)!=s.end()) {
            return true;
        }
        
        s.insert(root->val);
        
        return dfs(root->right, sum, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        
        unordered_set<int>s;
        return dfs(root, k, s);
    }
};