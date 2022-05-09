// Check if two tree are mirror of each other
// https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/


bool areMirror(Node* a, Node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;
 
    // If only one is empty
    if (a==NULL || b == NULL)
        return false;
 
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}


// For two trees to be mirror 

// three conditions must be true 

// [1] - Their root node's key must be same
// [2] - left subtree of left tree and right subtree of right tree have to be mirror images
// [3] - right subtree of left tree and left subtree of right tree have to be mirror images