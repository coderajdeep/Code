// geeks
// https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/

// iterative solution
// Level order traversal will be efficient
// Because there we need to traverse one node only one time

int getSize(Node* node)
{
    if(!node)
        return 0;
    queue<Node*>q;
    q.push(node);
    int size = 0;
    
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        size += 1;
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    return size;
}


// recursive solution

int getSize(Node* node)
{
   // Your code here
    if(!node) {
        return 0;
    }
    return 1 + getSize(node->left) + getSize(node->right);
}