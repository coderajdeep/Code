// leetcode 100

// recursive approace

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) {
            return true;
        }
        if(!p or !q) {
            return false;
        }
        
        return ((p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
    }
};


// iterative approach
// using queue<pair<TreeNode*, TreeNode*>>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        queue<pair<TreeNode*, TreeNode*>>Q;
        Q.push({p, q});
        TreeNode *r1, *r2;
        
        while(!Q.empty()) {
            r1 = Q.front().first;
            r2 = Q.front().second;
            Q.pop();
            
            if(r1->val != r2->val)
                return false;
            
            if(r1->left && r2->left) {
                Q.push({r1->left, r2->left});
            }
            else if(r1->left || r2->left)
                return false;
            
            if(r1->right && r2->right) {
                Q.push({r1->right, r2->right});
            }
            else if(r1->right || r2->right)
                return false;
        }
        return true;
    }
};


// iterative approach
// using two queue

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        
        TreeNode *curr1, *curr2;
        
        while(!q1.empty() && !q2.empty()) {
            curr1 = q1.front();
            curr2 = q2.front();
            q1.pop();
            q2.pop();
            
            if(curr1->val != curr2->val)
                return false;
            
            if(curr1->left && curr2->left) {
                q1.push(curr1->left);
                q2.push(curr2->left);
            }
            else if(curr1->left || curr2->left)
                return false;
            
            if(curr1->right && curr2->right) {
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
            else if(curr1->right || curr2->right)
                return false;
        }
        // not required
        // return q1.empty() && q2.empty();
        return true;
    }
};