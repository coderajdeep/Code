// https://techiedelight.com/practice/?id=TmTb
// leetcode - 99

// passing TreeNode* reference is important 

class Solution {
public:
    
    void dfs(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        
        if(!root) {
            return;
        }
        
        dfs(root->left, prev, first, second);
        
        if(prev and root->val < prev->val) {
            
            if(!first) {
                first = prev;
            }
            second = root;
        }
        
        prev = root;
        
        dfs(root->right, prev, first, second);
    }
    
    void recoverTree(TreeNode* root) {
        if(!root) {
            return;
        }
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        dfs(root, prev, first, second);
        
        cout<<first->val<<" "<<second->val<<"\n";
        
        swap(first->val, second->val);
    }
};


// techidelight code

// Recursive function to fix a binary tree that is only one swap
// away from becoming a BST. Here, `prev` is the previously processed node
// in inorder traversal, and `x` & `y` stores node to be swapped (if any).
void correctBST(Node* root, Node* &x, Node* &y, Node* &prev)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // recur for the left subtree
    correctBST(root->left, x, y, prev);
 
    // if the current node is less than the previous node
    if (root->data < prev->data)
    {
        // if this is the first occurrence, update `x` and `y` to the previous
        // and current node, respectively
        if (x == nullptr) {
            x = prev;
        }
 
        // if this is a second occurrence, update `y` to the current node
        y = root;
    }
 
    // update the previous node and recur for the right subtree
    prev = root;
    correctBST(root->right, x, y, prev);
}
 
// Fix given binary tree that is only one swap away from becoming a BST
void correctBST(Node* root)
{
    // `x` and `y` stores node to be swapped
    Node *x = nullptr, *y = nullptr;
 
    // stores previously processed node in the inorder traversal
    // initialize it by -INFINITY
    Node* prev = new Node(INT_MIN);
 
    // fix the binary tree
    correctBST(root, x, y, prev);
 
    // swap the nodes
    if (x && y) {
        swap(x->data, y->data);
    }
}