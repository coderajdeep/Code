// geeks
// https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/


// recursive approach

class Solution{
    public:
    int isSumProperty(Node *root)
    {
        if(!root) return 1;

        if(!root->left && !root->right) return 1;

        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        
        return ((root->data==sum && isSumProperty(root->left) && isSumProperty(root->right)) ? 1 : 0);
    }
};


// recursive approach

class Solution{
    public:
    int isSumProperty(Node *root)
    {
        if(!root) return 1;

        if(!root->left && !root->right) return 1;

        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;

        if(root->data!=sum) return 0;

        return ((isSumProperty(root->left) && isSumProperty(root->right)) ? 1 : 0);
    }
};


// recursive solution

int isSumProperty(Node *root) {
    if(!root)
        return 1;
    if(!root->left && !root->right)
        return 1;
        
    int sum = 0;
    
    if(root->left) {
        sum += root->left->data;
    }
    if(root->right) {
        sum += root->right->data;
    }
    
    return ((root->data == sum) && isSumProperty(root->left) && isSumProperty(root->right));
}


// iterative solution

int isSumProperty(Node *root){
    if(!root)
        return 1; // true
    if(!root->left && !root->right)
        return 1; // true
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        
        int sum = 0;
        // flag will check the corner case
        // leaf nodes
        bool flag = false;
        
        if(curr->left) {
            q.push(curr->left);
            sum += curr->left->data;
            flag = true;
        }
        if(curr->right) {
            q.push(curr->right);
            sum += curr->right->data;
            flag = true;
        }
        
        if((curr->data!=sum) && flag)
            return 0;
        
    }
    return 1;
}