// Time Complexity O(2*n)
// Space complexity O(2*w + n)

void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &um) {
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        if(curr->left) {
            q.push(curr->left);
            um[curr->left] = curr;
        }
        if(curr->right) {
            q.push(curr->right);
            um[curr->right] = curr;
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(!root || !target) return vector<int> {};
    unordered_map<TreeNode*, TreeNode*> um;
    findParents(root, um);
    queue<TreeNode*> q;
    q.push(target);
    unordered_set<TreeNode*>us;
    us.insert(target);
    int level = 0;
    TreeNode* curr;
    TreeNode* par;
    vector<int> ans;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            curr = q.front();
            q.pop();
            if(level==k) {
                ans.push_back(curr->val);
            }
            if(curr->left && us.find(curr->left)==us.end()) {
                q.push(curr->left);
                us.insert(curr->left);
            }
            if(curr->right && us.find(curr->right)==us.end()) {
                q.push(curr->right);
                us.insert(curr->right);
            }
            par = nullptr;
            if(curr!=root) {
                par = um[curr];
                if(us.find(par)==us.end()) {
                    q.push(par);
                    us.insert(par);
                }
            }
        }
        if(level==k) break;
        ++level;
    }
    return ans;
}