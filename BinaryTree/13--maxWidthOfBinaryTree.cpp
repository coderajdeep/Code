// leetcode 662
// ToDo 672
// Medium level

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int ans = 0;
        
        while(!q.empty()) {
            
            int t = q.size();
            int lo, hi;
            bool low = true;
            int minIndex;
            
            while(t--) {
                auto curr = q.front();
                q.pop();
                TreeNode* currNode = curr.first;
                int index = curr.second;
                
                if(low) {
                    minIndex = index;
                    lo = index-minIndex;
                    low = false;
                }
                
                // this is for handling overflow condition while doing 2*index
                // generally in sparse tree
                
                index = index - minIndex;
                
                if(t==0) {
                    hi = index;
                }
                
                
                if(currNode->left) {
                    q.push({currNode->left, (2*index + 1)});
                }
                
                if(currNode->right) {
                    q.push({currNode->right, (2*index + 2)});
                }
            }
            
            ans = max(ans, (hi-lo+1));
        }
        return ans;
    }
};

/*

[1,1,1,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,
null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,
null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,null,
1,1,null,1,null,1,null,1,null,1,null,null,null,1]

*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        long long ans = 0;
        
        while(!q.empty()) {
            
            int t = q.size();
            long long hi;
            // long long lo;
            bool low = true;
            long minIndex;
            
            while(t--) {
                auto curr = q.front();
                q.pop();
                TreeNode* currNode = curr.first;
                long long index = curr.second;
                
                if(low) {
                    minIndex = index;
                    // lo = index-minIndex;
                    // lo will always be zero
                    low = false;
                }
                
                index = index - minIndex;
                
                if(t==0) {
                    hi = index;
                }
                
                
                if(currNode->left) {
                    q.push({currNode->left, (2*index + 1)});
                }
                
                if(currNode->right) {
                    q.push({currNode->right, (2*index + 2)});
                }
            }
            
            // ans = max(ans, (hi-lo+1));
            ans = max(ans, (hi+1));
        }
        return ans;
    }
};



// geeks

// iterative solution
// similar to level order iterative search
class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        if(!root) {
            return 0;
        }
        
        queue<Node*>q;
        q.push(root);
        int ans = 0;
        
        while(!q.empty()) {
            int t = q.size();
            ans = max(ans, t);
            
            while(t--) {
                Node *curr = q.front();
                q.pop();
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};

// recursive solution
// Time O(n2)

class Solution {
  public:
  
    int dfs(Node *root, int level) {
        if(!root) {
            return 0;
        }
        
        if(level==1) {
            return 1;
        }
        
        return dfs(root->left, level-1) + dfs(root->right, level-1);
    } 
    
    int height(Node *root) {
        return ((root==nullptr) ? 0 : 1 + max(height(root->left), height(root->right)));
    }
  
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        if(!root) {
            return 0;
        }
        
        int h = height(root);
        int ans = 0;
        
        for(int i=1; i<=h; ++i) {
            ans = max(ans, dfs(root, i));
        }
        
        return ans;
    }
};
