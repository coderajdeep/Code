// leetcode 572

// O(n) time solution

class Solution {
public:
    
    void inorder(TreeNode *root, string &path) {
        if(!root) {
            path.push_back('e');
            return;
        }
        
        inorder(root->left, path);
        
        path.push_back('x');
        path += to_string(root->val);
        path.push_back('x');
        
        inorder(root->right, path);
    }
    
    void preorder(TreeNode *root, string &path) {
        if(!root) {
            path.push_back('e');
            return;
        }
        
        path.push_back('x');
        path += to_string(root->val);
        path.push_back('x');
        
        preorder(root->left, path);
        preorder(root->right, path);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root) return false;
        
        string t1, t2;
        inorder(root, t1);
        inorder(subRoot, t2);
        if(t1.find(t2)==string::npos) return false;
        
        t1.clear(); t2.clear();
        preorder(root, t1);
        preorder(subRoot, t2);
        if(t1.find(t2)==string::npos) return false;
        
        return true;
    }
};


// Time O(n*m)
// Optimized to O(n)

// recursive approach

class Solution {
public:
    
    bool isSame(TreeNode *t1, TreeNode *t2) {
        if(!t1 and !t2) {
            return true;
        }
        if(!t1 or !t2) {
            return false;
        }
        return ((t1->val == t2->val) and isSame(t1->left, t2->left) and isSame(t1->right, t2->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) {
            return true;
        }
        if(!root) {
            return false;
        }
        if(isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};