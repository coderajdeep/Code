// leetcode 106
// Time complexity - O(n2)
// We can improve time complexity by using hashing - O(n)

class Solution {
public:
    
    TreeNode* getTree(vector<int> &in, vector<int> &post, int inStart, int inEnd, int &postIndex) {
        if(inStart > inEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(post[postIndex--]);
        int inIndex;
        
        for(int i=inStart; i<=inEnd; ++i) {
            if(in[i]==root->val) {
                inIndex = i;
                break;
            }
        }
        
        // if postorder and inorder is given
        // then we will build tree in postorder fashion
        // root->right will come fast
        // then root->left

        root->right = getTree(in, post, inIndex+1, inEnd, postIndex);
        root->left = getTree(in, post, inStart, inIndex-1, postIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int inStart = 0, inEnd = (inorder.size() - 1), postIndex = (postorder.size() - 1);
        
        TreeNode *root = getTree(inorder, postorder, inStart, inEnd, postIndex);
        
        return root;
    }
};