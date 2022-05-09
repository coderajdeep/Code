// leetcode 103

// best solution

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp(size);
            
            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                
                int index = leftToRight ? i : (size-i-1) ;
                temp[index] = curr->val;
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp;
            
            for(int i=0; i<size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            
            bool flag = (level%2==0) ? true : false;
            ++level;
            
            if(flag) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};