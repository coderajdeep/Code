// geeks
// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree/
// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/
// https://www.geeksforgeeks.org/k-th-ancestor-of-a-node-in-binary-tree-set-3/

// Time - O(n) space - O(h)[for function call stack] + O(h) [for array]
bool dfs(Node *root, int target, vector<int>&arr) {
    if(!root) {
        return false;
    }
    if(root->data == target) {
        return true;
    }
    if(dfs(root->left, target, arr) or dfs(root->right, target, arr)) {
        arr.push_back(root->data);
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(!root) {
        return -1;
    }
    
    vector<int>arr;
    
    dfs(root, node, arr);
    
    int n = arr.size();
    
    if(arr.empty() or k>n) {
        return -1;
    }
    
    return arr[k-1];
}


// space optimized
// // Time - O(n) space - O(h) [for function call stack]

bool dfs(Node *root, int target, int k, int &level, int &ans) {
    if(!root) {
        return false;
    }
    if(root->data == target) {
        return true;
    }
    if(dfs(root->left, target, k, level , ans) or dfs(root->right, target, k, level , ans)) {
        if(k == level) {
            ans = root->data;
        }
        ++level;
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(!root) {
        return -1;
    }
    int level = 1, ans = INT_MIN;
    if(dfs(root, node, k, level, ans) and ans!=INT_MIN) {
        return ans;
    }
    return -1;
}