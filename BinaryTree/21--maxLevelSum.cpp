// leetcode 1161

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        int maxSum = INT_MIN, minLevel = 1, level = 1;
        
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;

            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(maxSum<sum) {
                maxSum = sum;
                minLevel = level;
            }
            ++level;
        }
        return minLevel;
    }
};