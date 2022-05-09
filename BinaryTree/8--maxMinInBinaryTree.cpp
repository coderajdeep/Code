// geeks
// https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/

// recursive solution

class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        if(!root) {
            return INT_MIN;
        }
        
        int lm = findMax(root->left);
        int rm = findMax(root->right);
        
        return max({root->data, lm, rm});
    }
    int findMin(Node *root)
    {
        //code here
        if(!root) {
            return INT_MAX;
        }
        
        int lm = findMin(root->left);
        int rm = findMin(root->right);
        
        return min({root->data, lm, rm});
    }
};

// iterative solution

class Solution
{
public:
    int findMax(Node *root)
    {
        if(!root)
            return INT_MIN;
        queue<Node*>q;
        q.push(root);
        int ans = INT_MIN;
        
        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            ans = max(ans, curr->data);
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return ans;
    }
    int findMin(Node *root)
    {
        if(!root)
            return INT_MAX;
        queue<Node*>q;
        q.push(root);
        int ans = INT_MAX;
        
        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            ans = min(ans, curr->data);
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return ans;
    }
};