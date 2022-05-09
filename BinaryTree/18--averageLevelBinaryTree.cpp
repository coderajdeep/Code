// leetcode 637

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {
            
            int t = q.size();
            int num = t;
            double sum = 0.0;
            
            for(int i=0; i<t; ++i) {
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
            double avg = sum/num;
            ans.push_back(avg);
        }
        return ans;
    }
};