// leetcode 105
// Time complexity - O(n2)
// We can improve time complexity by using hashing - O(n)

class Solution {
public:
    
    TreeNode* getTree(vector<int>&pre, vector<int>&in, int inStart, int inEnd, int &preIndex) {
        
        if(inStart>inEnd) {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(pre[preIndex++]);
        
        int inIndex;
        
        for(int i=inStart; i<=inEnd; ++i) {
            if(in[i] == root->val) {
                inIndex = i;
                break;
            }
        }

        // if preorder and inorder is given
        // then we will build tree in preorder fashion
        // root->left will come fast
        // then root->right
        
        root->left = getTree(pre, in, inStart, inIndex-1, preIndex);
        root->right = getTree(pre, in, inIndex+1, inEnd, preIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndex = 0, inStart = 0, inEnd = inorder.size()-1;
        
        TreeNode *root = getTree(preorder, inorder, inStart, inEnd, preIndex);
        
        return root;
    }
};