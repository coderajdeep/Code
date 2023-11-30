// Time Complexity O(nlogn)
// Space Complexity O(2*n)

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(!root) return vector<vector<int>> {};

    queue<pair<TreeNode*, pair<int, int>>> q;
    // <root <hLevel, vLevel>>
    map<int, multiset<pair<int, int>>> mp;
    // <vLevel <hLevel, nodeValue>>
    q.push({root, {1, 0}});
    pair<TreeNode*, pair<int, int>> temp;
    TreeNode* node;
    int hLevel, vLevel, index, n;

    while(!q.empty()) {
        temp = q.front();
        q.pop();
        node = temp.first;
        hLevel = temp.second.first;
        vLevel = temp.second.second;

        mp[vLevel].insert({hLevel, node->val});

        if(node->left) {
            q.push({node->left, {hLevel+1, vLevel-1}});
        }
        if(node->right) {
            q.push({node->right, {hLevel+1, vLevel+1}});
        }
    }

    vector<vector<int>> ans(mp.size());
    int ansIndex = 0;
    for(auto _mp : mp) {
        auto _ms = _mp.second;
        n = _ms.size();
        vector<int> vLevelList(n);
        index = 0;
        for(pair<int, int> p:_ms) {
            vLevelList[index++] = p.second;
        }
        ans[ansIndex++] = vLevelList;
    }
    return ans;
}