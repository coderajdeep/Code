// Time complexity O(h)
// Space complexity O(h)
void dfs(BinaryTreeNode<int> *node, int &cl, int x) {
    if(!node) {
        return;
    }
    else if(node->data==x) {
        cl = x;
        return;
    }
    else if(node->data > x) {
        cl = node->data;
        dfs(node->left, cl, x);
    }
    else {
        dfs(node->right, cl, x);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    if(!node) {
        return -1;
    }
    int cl = -1;
    dfs(node, cl, x);
    return cl;
}