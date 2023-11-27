// leetcode
// Time complexity O(n)
// Space complexity O(n)
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void revrseVector(vector<int>& arr) {
    int start = 0, end = arr.size()-1;
    while(start<end) {
        swapElements(arr[start++], arr[end--]);
    }
} 

vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return vector<int> {};

    vector<int> postorder;
    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* curr = nullptr;

    while(!stk.empty()) {
        curr = stk.top();
        stk.pop();
        postorder.push_back(curr->val);
        if(curr->left) {
            stk.push(curr->left);
        }
        if(curr->right) {
            stk.push(curr->right);
        }
    }

    revrseVector(postorder);

    return postorder;
}