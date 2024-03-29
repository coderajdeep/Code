// leetcode 111 (Min depth)
// leetcode 104 (Max depth)

// https://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/
// recursive solution
// can be solved using levle order traversal - iterative method

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        if(!root->left and !root->right) {
            return 1;
        }
        
        int ld = INT_MAX, rd = INT_MAX;
        
        if(root->left) {
            ld = minDepth(root->left);
        }
        
        if(root->right) {
            rd = minDepth(root->right);
        }
        
        return (1 + min(ld, rd));
    }
};

// [2,null,3,null,4,null,5,null,6]
// this solution will not work
// Just dry run this test case
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(!root) return 0;
//         if(!root->left && !root->right) return 1;
//         return 1 + min(minDepth(root->left), minDepth(root->right));
//     }
// };


// iterative solution

class Solution {
public:
    
    bool isLeaf(TreeNode *root) {
        if(root and !root->left and !root->right) {
            return true;
        }
        return false;
    }
    
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        
        while(!q.empty()) {
            int t = q.size();
            
            while(t--) {
                TreeNode *curr = q.front();
                q.pop();
                
                if(isLeaf(curr)) {
                    return level;
                }
                
                if(curr->left) {
                    q.push(curr->left);
                }
                
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            
            ++level;
        }
        return -1;
    }
};



// leetcode 104

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        
        return 1 + max(ld, rd);
    }
};