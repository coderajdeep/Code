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
            
            int size = q.size();
            double sum = 0.0;
            
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
            double avg = sum/size;
            ans.push_back(avg);
        }
        return ans;
    }
};