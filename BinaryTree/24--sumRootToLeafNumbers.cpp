// Leetcode 129

class Solution {
public:
    
    int getSum(vector<int>&arr) {
        int n = arr.size();
        int sum = 0;
        long mul = 1;
        
        for(int i=n-1; i>=0; --i) {
            sum += (arr[i]*mul);
            mul *= 10;
        }
        return sum;
    }
    
    void dfs(TreeNode *root, vector<int>&temp, vector<vector<int>>&ans) {
        if(!root) {
            return;
        }
        
        temp.push_back(root->val);
        
        if(!root->left and !root->right) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        dfs(root->left, temp, ans);
        dfs(root->right, temp, ans);
        
        temp.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        dfs(root, temp, ans);
        
        int total = 0;
        
        for(auto arr:ans) {
            total += getSum(arr);
        }
        
        return total;
    }
};