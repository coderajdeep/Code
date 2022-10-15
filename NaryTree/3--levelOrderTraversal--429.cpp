class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()) {
            int levelSize = q.size();
            vector<int>level(levelSize);
            for(int i=0; i<levelSize; ++i) {
                Node *curr = q.front();
                q.pop();
                level[i] = curr->val;
                int n = curr->children.size();
                for(int i=0; i<n; ++i) q.push(curr->children[i]);
            }
            ans.push_back(level);
        }
        return ans;
    }
};