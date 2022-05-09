// leetcode 297


// using preorder traversal

class Codec {
public:
    
    void dfs(TreeNode *root, string &ans) {
        if(!root) {
            ans += "x_";
            return;
        }
        ans += to_string(root->val);
        ans.push_back('_');
        
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "x_";
        }
        string ans;
        dfs(root, ans);
        return ans;
    }
    
    vector<string> splitString(string &s) {
        vector<string>ans;
        string str = "";
        int n = s.size();
        
        for(int i=0; i<n; ++i) {
            if(s[i]!='_') {
                str.push_back(s[i]);
            }
            else {
                ans.push_back(str);
                str.clear();
            }
        }
        return ans;
    }
    
    TreeNode* dfs2(vector<string> &tree, int &index) {
        // when every value in str is traversed then this condition will be true
        // if(tree.size()==index) {
        //     return nullptr;
        // }
        // this condition is not required
        // because next if condition will handle it (s=="x")
        
        string s = tree[index++];
        
        if(s=="x") {
            return nullptr;
        }
        
        int val = stoi(s);
        
        TreeNode *root = new TreeNode(val);
        
        root->left = dfs2(tree, index);
        root->right = dfs2(tree, index);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tree = splitString(data);
        int index = 0;
        
        TreeNode *root = dfs2(tree, index);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));