// leetcode - 113
// Path Sum II
// Tricky


// The best solution

class Solution {
public:
    
    void solve(TreeNode *root, int &targetSum, vector<int> &ds, vector<vector<int>> &ans) {
        if(!root) return;
        
        ds.push_back(root->val);
        targetSum -= root->val;
        
        if(!root->left && !root->right && !targetSum) ans.push_back(ds);
        
        solve(root->left, targetSum, ds, ans);
        solve(root->right, targetSum, ds, ans);
        
        ds.pop_back();
        targetSum += root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(root, targetSum, ds, ans);
        
        return ans;
        
    }
};


// Best solution

class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        return (!root->left and !root->right) ? true : false ;
    }
    
    void dfs(TreeNode *root, int targetSum, vector<int>&temp, vector<vector<int>>&ans) {
        if(!root) {
            return;
        }
        
        temp.push_back(root->val);
        
        if(isLeaf(root) and root->val==targetSum) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        dfs(root->left, targetSum - root->val, temp, ans);
        dfs(root->right, targetSum - root->val, temp, ans);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return {};
        }
        vector<int>temp;
        vector<vector<int>>ans;
        
        dfs(root, targetSum, temp, ans);
        
        return ans;
    }
};

// Best solution

class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        return (!root->left and !root->right) ? true : false ;
    }
    
    void dfs(TreeNode *root, int targetSum, vector<int>&temp, vector<vector<int>>&ans) {
        if(!root) {
            return;
        }
        
        temp.push_back(root->val);
        
        if(isLeaf(root) and root->val==targetSum) {
            ans.push_back(temp);
        }
        
        dfs(root->left, targetSum - root->val, temp, ans);
        dfs(root->right, targetSum - root->val, temp, ans);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return {};
        }
        vector<int>temp;
        vector<vector<int>>ans;
        
        dfs(root, targetSum, temp, ans);
        
        return ans;
    }
};


class Solution {
public:
    
    void solve(TreeNode *root, int targetSum, vector<int> &ds, vector<vector<int>> &ans) {
        if(!root) return;
        
        ds.push_back(root->val);
        targetSum -= root->val;
        
        if(!root->left && !root->right && !targetSum) ans.push_back(ds);
        
        solve(root->left, targetSum, ds, ans);
        solve(root->right, targetSum, ds, ans);
        
        ds.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(root, targetSum, ds, ans);
        
        return ans;
        
    }
};


class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        return (!root->left and !root->right) ? true : false ;
    }
    
    void dfs(TreeNode *root, int targetSum, vector<int>temp, vector<vector<int>>&ans) {
        if(!root) {
            return;
        }
        temp.push_back(root->val);
        
        if(isLeaf(root) and (root->val==targetSum)) {
            ans.push_back(temp);
            // we can remove below return
            // if we remove below return then then there will be two more function call
            return;
        }
        dfs(root->left, targetSum - root->val, temp, ans);
        dfs(root->right, targetSum - root->val, temp, ans);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return {};
            // not {{}}
            // vector<vector<int>>arr1 = {{}} ---> arr1.size() == 1
            // vector<int>arr2 = {} ---> arr2.size() == 1
            // https://ideone.com/EYcYbN
        }
        vector<int>temp;
        vector<vector<int>>ans;
        
        dfs(root, targetSum, temp, ans);
        
        return ans;
    }
};


// below two are old solution

// very good solution
// Time O(n) solution 

class Solution {
public:
    
    void solve(TreeNode *root, int target, vector<int> &temp, vector<vector<int>> &ans) {
        if(!root)
            return;
        temp.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(root->val == target) {
                ans.push_back(temp);
            }
            
            // if remove below two line then also code will work
            // but there will be two different function call
            temp.pop_back();
            return;
        }
        solve(root->left, target-(root->val), temp, ans);
        solve(root->right, target-(root->val), temp, ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        vector<int> temp;
        vector<vector<int>> ans;
        
        solve(root, targetSum, temp, ans);
        
        return ans;
    }
};


// Below solution we are not passing temp reference
// so it will take more time

class Solution {
public:
    
    void solve(TreeNode *root, int target, vector<int> temp, vector<vector<int>> &ans) {
        if(!root)
            return;
        temp.push_back(root->val);
        
        if(!root->left && !root->right) {
            if((root->val)==target)
                ans.push_back(temp);
        }
        
        solve(root->left, target-(root->val), temp, ans);
        solve(root->right, target-(root->val), temp, ans);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        // {{}} -> it means outer vector has one element and inside vector is empty
        
        vector<int> temp;
        vector<vector<int>> ans;
        
        solve(root, targetSum, temp, ans);
        
        return ans;
    }
};