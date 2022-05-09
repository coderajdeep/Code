// geeks
// https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/

class Solution{
  public:
    // Function should return all the ancestor of the target node
    
    bool dfs(Node *root, int target, vector<int> &ans) {
        if(!root) {
            return false;
        }
        if(root->data == target) {
            return true;
        }
        if(dfs(root->left, target, ans) or dfs(root->right, target, ans)) {
            ans.push_back(root->data);
            return true;
        }
        return false;
    }
    
    vector<int> Ancestors(struct Node *root, int target)
    {
         // Code here
         if(!root) {
             return {};
         }
         vector<int>ans;
         
         dfs(root, target, ans);
         
         return ans;
    }
};