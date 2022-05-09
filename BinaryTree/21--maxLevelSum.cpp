// leetcode 1161

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) {
            return {};
        }

        queue<TreeNode*>q;
        q.push(root);
        int level = 1, maxLevel = 1, maxSum = INT_MIN;
        
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            
            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                
                sum += (curr->val);
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            
            if(maxSum<sum) {
                maxSum = sum;
                maxLevel = level;
            }
            
            ++level;
        }
        
        return maxLevel;
    }
};